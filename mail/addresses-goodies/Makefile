PORTNAME=	addresses
PORTVERSION=	0.4.8
PORTREVISION=	11
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMESUFFIX=	-goodies${PKGNAMESUFFIX2}
DISTNAME=	Addresses-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Goodies for addressbook for GNUstep
WWW=		https://giesler.biz/bjoern/en/sw_addr.html

LICENSE=	LGPL21

USES=		gnustep
USE_GNUSTEP=	back build

LIB_DEPENDS=	libInspector.so:deskutils/gworkspace \
		libAddresses.so:mail/addresses
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Addresses-${PORTVERSION}/Goodies

post-patch:
	${REINPLACE_CMD} -e 's|LDAPAddressBook||' \
		-e 's|VCFViewer||' \
		${WRKSRC}/GNUmakefile
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		-e 's|Library/GWorkspace|Library/Bundles|' \
		-e 's|-lGWorkspace|-lInspector|' \
		${WRKSRC}/VCFViewer/GNUmakefile
	${REINPLACE_CMD} -e 's|<GWorkspace/|<Inspector/|' \
		${WRKSRC}/VCFViewer/VCFViewer.h

.include <bsd.port.mk>
