# $FreeBSD$

PORTNAME=	addresses
PORTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=   ${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=     gap
PKGNAMESUFFIX=	-goodies${PKGNAMESUFFIX2}
DISTNAME=	Addresses-${PORTVERSION}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Goodies for addressbook for GNUstep

LICENSE=	LGPL21

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	Inspector:${GWORKSPACE_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	Addresses:${ADDRESSES_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/Addresses-${PORTVERSION}/Goodies

ADDRESSES_PORT?=	mail/addresses
GWORKSPACE_PORT?=	deskutils/gworkspace

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
