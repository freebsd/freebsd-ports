# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	3.5.8
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

LICENSE=	LGPL21

CONFLICTS_INSTALL=	tinymce-[0-24-9]*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		cpe zip

post-extract:
	@cd ${WRKSRC}/ && ${FIND} -s * -type d -empty | ${XARGS} -I % ${TOUCH} %/.keepme

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	${ECHO} "@owner www" > ${MS_PLIST}
	${ECHO} "@group www" >> ${MS_PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
	${ECHO} "@owner" >> ${MS_PLIST}
	${ECHO} "@group" >> ${MS_PLIST}
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
