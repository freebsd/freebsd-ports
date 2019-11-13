# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	zenphoto
PORTVERSION=	1.5.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simpler web photo gallery

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:flavors,web
USE_PHP=	gd gettext hash json mbstring mysqli pcre session

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-deinstall pkg-message

USE_GITHUB=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/cache/
	@${FIND} ${WRKSRC} -name '.git*' -delete
	@${RM} ${WRKSRC}/zp-core/Zenphoto.package

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	@${ECHO_CMD} '@owner www' > ${MS_PLIST}
	@${ECHO_CMD} '@group www' >> ${MS_PLIST}
	@cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SORT} | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
	@cd ${WRKSRC}/ && (${FIND} -s * -type d -empty | ${XARGS} -I _ ${ECHO_CMD} '@dir %%WWWDIR%%/_') >> ${MS_PLIST}
	@${ECHO_CMD} '@owner' >> ${MS_PLIST}
	@${ECHO_CMD} '@group' >> ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
