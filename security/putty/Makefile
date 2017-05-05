# $FreeBSD$

PORTNAME=	putty
PORTVERSION=	0.69
CATEGORIES=	security ipv6
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/${PORTVERSION}/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/

# Beat Gaetzi (beat@) is permitted to take maintainership back
# or commit to this port without my prior approval.
MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure shell and telnet client

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE

USES=		cpe gmake pkgconfig
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAKEFILE=	Makefile.gtk

CPE_VENDOR=	simon_tatham

PLIST_FILES=	bin/plink bin/pscp bin/psftp bin/puttygen
PLIST_FILES+=	man/man1/plink.1.gz man/man1/pscp.1.gz man/man1/psftp.1.gz man/man1/puttygen.1.gz

OPTIONS_DEFINE=	GSSAPI GTK3
OPTIONS_DEFAULT=GSSAPI GTK3

CONFLICTS_INSTALL?=	pssh-[0-9]* putty-nogtk-[0-9]*

.include <bsd.port.options.mk>

CFLAGS+=	-DBSD_PTYS -DOMIT_UTMP -DIPV6
LDFLAGS+=	-Wl,--as-needed

.if ${PORT_OPTIONS:MGTK3} && !defined(WITHOUT_X11)
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11

PLIST_FILES+=	bin/pageant bin/pterm bin/putty bin/puttytel
PLIST_FILES+=	man/man1/pageant.1.gz man/man1/pterm.1.gz man/man1/putty.1.gz man/man1/puttytel.1.gz
MAKE_ARGS+=	PUTTY_WITH_GTK=yes GTK_CONFIG="pkg-config gtk+-3.0 x11 --cflags"
.else
MAKE_ARGS+=	GTK_CONFIG=:
.endif

.if ${PORT_OPTIONS:MGSSAPI}
_COMPAT=		-DSTATIC_GSSAPI
USES+=		gssapi:base,flags
MAKE_ARGS+=	KRB5CONFIG=${KRB5CONFIG}
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
			      s,make,${MAKE_CMD},'\
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
