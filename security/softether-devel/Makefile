# $FreeBSD$

PORTNAME=	softether-devel
PORTVERSION=	4.21.9613
PORTREVISION=	2
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

OPTIONS_DEFINE= DOCS UNLOCK

# Use of some functions in Japan and China is restricted.
# This option Unlocks regional lockout following functions:
#  - RADIUS / NT Domain user authentication function
#  - RSA certificate user authentication function
#  - Deep-inspect packet logging function
#  - Source IP address control list function
#  - syslog transfer function
UNLOCK_DESC= Unlock regional lockout (JP and CN)
UNLOCK_EXTRA_PATCHES=   ${FILESDIR}/extra-patch-unrestrict-enterprise-functions

post-patch:
	${INSTALL_DATA} ${WRKSRC}/src/makefiles/freebsd_32bit.mak \
	    ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
