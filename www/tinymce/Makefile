PORTNAME=	tinymce
PORTVERSION=	8.0.0
CATEGORIES=	www
MASTER_SITES=	http://download.tiny.cloud/tinymce/community/ \
		LOCAL/sunpoet
DISTNAME=	tinymce_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites
WWW=		https://www.tiny.cloud/ \
		https://www.tiny.cloud/docs/tinymce/latest/ \
		https://github.com/tinymce/tinymce

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/js/tinymce/license.md

USES=		cpe zip

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tinymce

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	@${ECHO_CMD} "@owner www" > ${MS_PLIST}
	@${ECHO_CMD} "@group www" >> ${MS_PLIST}
	@cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
	@${ECHO_CMD} "@owner" >> ${MS_PLIST}
	@${ECHO_CMD} "@group" >> ${MS_PLIST}
	@${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
