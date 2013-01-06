# $FreeBSD$

PORTNAME=	putty
PORTVERSION=	0.62
PORTREVISION=	2
CATEGORIES=	security ipv6
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/%SUBDIR%/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/
MASTER_SITE_SUBDIR=	${PORTVERSION}

# Beat Gaetzi (beat@) is permitted to take maintainership back
# or commit to this port without my prior approval.
MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure shell and telnet client

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAKEFILE=	Makefile.gtk

PLIST_FILES=	bin/plink bin/pscp bin/psftp bin/puttygen
MAN1=		plink.1 pscp.1 psftp.1 puttygen.1

OPTIONS_DEFINE=	GSSAPI GTK2
OPTIONS_DEFAULT=GSSAPI GTK2

CONFLICTS=	pssh-[0-9]*

.include <bsd.port.options.mk>

CFLAGS+=	-DBSD_PTYS -DOMIT_UTMP -DIPV6

.if ${PORT_OPTIONS:MGTK2} && !defined(WITHOUT_X11)
USE_GNOME=	gtk20
PLIST_FILES+=	bin/pterm bin/putty bin/puttytel
MAN1+=		pterm.1 putty.1 puttytel.1
MAKE_ARGS+=	PUTTY_WITH_GTK=yes GTK_CONFIG="pkg-config gtk+-2.0 x11 --cflags"
.else
MAKE_ARGS+=	GTK_CONFIG=:
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGSSAPI}
_COMPAT=		-DSTATIC_GSSAPI
.if ${OSVERSION} >= 900000
LIB_DEPENDS+=		krb5support:${PORTSDIR}/security/krb5
.endif
.else
_COMPAT=		-DNO_GSSAPI
.endif

_COMPAT+=	-DOMIT_UTMP

.if defined(WITH_DEBUG) && ${WITH_DEBUG} != "no"
XFLAGS=		-DDEBUG
.endif

# upstream sets -Werror - there are no issues on 9.1-FreeBSD amd64
# currently, but override it nonetheless.
XFLAGS+=	-Wno-error

MAKE_ARGS+=	COMPAT="${_COMPAT}" \
		CC="${CC}" \
		XFLAGS="${XFLAGS}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-patch:
	@${REINPLACE_CMD} -e 's,prefix=/usr/local,prefix=${PREFIX},;\
			      s,make,${GMAKE},'\
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.post.mk>
