# $FreeBSD$

PORTNAME=	msiklm
DISTVERSION=	g20180227
CATEGORIES=	sysutils

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MSI keyboard light manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	This hardware is only found on x86 systems

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		dos2unix localbase:ldflags uidfix
DOS2UNIX_FILES=	README.md
USE_GITHUB=	yes
GH_ACCOUNT=	Gibtnix
GH_PROJECT=	MSIKLM
GH_TAGNAME=	46dd076

MAKEFILE=	${FILESDIR}/Makefile.bsd
PLIST_FILES=	bin/msiklm
PORTDOCS=	README.md

OPTIONS_DEFINE=		DEVD DOCS
OPTIONS_DEFAULT=	DEVD

DEVD_PLIST_FILES=	etc/devd/msiklm.conf.sample
DEVD_SUB_FILES=		msiklm.conf.sample pkg-message

post-install-DEVD-on:
	${INSTALL_DATA} ${WRKDIR}/msiklm.conf.sample ${STAGEDIR}${PREFIX}/etc/devd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
