# New ports collection makefile for:    opennx
# Date created:                         Fri 29 Jul 2011
# Whom:                                 Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	opennx
PORTVERSION=	0.16.0.709
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CI-source

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open source drop in replacement for NoMachine\'s NX client

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	smbclient:${PORTSDIR}/net/samba-libsmbclient \
		cups:${PORTSDIR}/print/cups-base

WRKSRC=		${WRKDIR}/${PORTNAME}-0.16

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	xmu
USE_WX=		2.8+
WX_UNICODE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include

MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

NO_PACKAGE=	must generate a fresh private key at install time

SSH_KEYGEN?=	/usr/bin/ssh-keygen

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls --localedir=/dev/null
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

# do not use default private key included with tarball
post-patch:
	@${RM} ${WRKSRC}/share/keys/server.id_dsa.key
	@${SSH_KEYGEN} -N '' -b 2048 -q -f ${WRKSRC}/share/keys/server.id_dsa.key

post-install:
	@${CHMOD} 440 ${PREFIX}/share/keys/server.id_dsa.key

.include <bsd.port.mk>
