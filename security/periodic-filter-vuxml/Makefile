PORTNAME=	periodic-filter-vuxml
PORTVERSION=	1
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Periodic script to install a filtered version of VuXML

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	xml:textproc/xmlstarlet

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
SUB_FILES=	400.filter-vuxml
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/periodic/security/400.filter-vuxml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/security
	${INSTALL_SCRIPT} ${WRKDIR}/400.filter-vuxml \
		${STAGEDIR}${PREFIX}/etc/periodic/security

.include <bsd.port.mk>
