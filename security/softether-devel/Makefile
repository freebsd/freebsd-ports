# $FreeBSD$

PORTNAME=	softether-devel
PORTVERSION=	4.21.9613
CATEGORIES=	security

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Cross-platform Multi-protocol VPN Software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	softether

USES=		dos2unix gmake iconv localbase readline ssl
DOS2UNIX_FILES=	src/Mayaqua/Network.c
USE_GITHUB=	yes
GH_ACCOUNT=	SoftEtherVPN
GH_PROJECT=	SoftEtherVPN
GH_TAGNAME=	1e17c9b
ALL_TARGET=	build
MAKE_ENV=	STAGEDIR=${STAGEDIR} ICONV_LIB=${ICONV_LIB}
USE_RC_SUBR=	vpnserver vpnclient vpnbridge
PORTDOCS=	AUTHORS.TXT BUILD_UNIX.TXT ChangeLog README THIRD_PARTY.TXT \
		WARNING.TXT

OPTIONS_DEFINE=	DOCS

post-patch:
	${INSTALL_DATA} ${WRKSRC}/src/makefiles/freebsd_32bit.mak \
	    ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
