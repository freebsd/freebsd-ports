# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	yourls
PORTVERSION=	1.8
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Your Own URL Shortener

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php
USE_PHP=	bcmath curl json mysqli pcre xml

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

GH_ACCOUNT=	YOURLS
GH_PROJECT=	YOURLS
USE_GITHUB=	yes

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	@${ECHO} "@owner www" > ${MS_PLIST}
	@${ECHO} "@group www" >> ${MS_PLIST}
	@cd ${WRKSRC}/ && ${FIND} -s . -type f | ${SED} 's|^\.|%%WWWDIR%%|' >> ${MS_PLIST}
	@${ECHO} "@owner" >> ${MS_PLIST}
	@${ECHO} "@group" >> ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
