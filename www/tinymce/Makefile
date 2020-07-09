# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	5.4.1
CATEGORIES=	www
MASTER_SITES=	http://download.tiny.cloud/tinymce/community/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/js/tinymce/license.txt

USES=		cpe zip

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	@${ECHO} "@owner www" > ${MS_PLIST}
	@${ECHO} "@group www" >> ${MS_PLIST}
	@cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
	@${ECHO} "@owner" >> ${MS_PLIST}
	@${ECHO} "@group" >> ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
