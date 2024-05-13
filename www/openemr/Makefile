PORTNAME=	openemr
PORTVERSION=	7.0.2
CATEGORIES=	www
MASTER_SITES=	SF/openemr/OpenEMR%20Current/${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Electronic health records and medical practice management application
WWW=		https://www.open-emr.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:flavors
USE_PHP=	ctype curl gd json ldap mcrypt \
		mbstring openssl pdo pdo_mysql \
		session xml xmlreader xmlrpc xsl zip zlib

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	OPENEMRDIR=${OPENEMRDIR}

OPENEMRDIR?=	www/openemr

post-patch:
	@${RM} -rf ${WRKSRC}/.g*
	@${RM} -rf ${WRKSRC}/.e*
	@${RM} -rf ${WRKSRC}/.s*

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${OPENEMRDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type l | ${SED} "s?${WRKSRC}?${OPENEMRDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s?${WRKSRC}?@dir ${OPENEMRDIR}?g" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${OPENEMRDIR}

.include <bsd.port.mk>
