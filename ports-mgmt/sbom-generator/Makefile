PORTNAME=	sbom-generator
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Create SPDX SBOM files for installed packages
WWW=		https://www.FreeBSD.org/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	bomtool:devel/pkgconf \
		spdxtool:devel/pkgconf

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	sbom-generator
SUB_LIST=	LOCALBASE=${LOCALBASE}

PLIST_FILES=	bin/sbom-generator \
		share/man/man1/sbom-generator.1.gz

do-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sbom-generator \
	    ${STAGEDIR}${PREFIX}/bin/sbom-generator
	${INSTALL_MAN} ${FILESDIR}/sbom-generator.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
