# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	4.0.20
CATEGORIES=	www
MASTER_SITES=	http://download.moxiecode.com/${PORTNAME}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

LICENSE=	LGPL21

CONFLICTS_INSTALL=	tinymce-[0-35-9]* tinymce3-[0-9]*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		zip

post-extract:
	@cd ${WRKSRC}/ && ${FIND} -s * -type d -empty | ${XARGS} -I % ${TOUCH} %/.keepme

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

#MS_DIRRMTRY=	# empty
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	${ECHO} "@owner www" > ${MS_PLIST}
	${ECHO} "@group www" >> ${MS_PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type d | ${TAIL} -r | ${SED} 's|^|@dirrm %%WWWDIR%%/|' >> ${MS_PLIST}
	${ECHO} '@dirrmtry %%WWWDIR%%' >> ${MS_PLIST}
	${ECHO} "@owner" >> ${MS_PLIST}
	${ECHO} "@group" >> ${MS_PLIST}
#.for dir in ${MS_DIRRMTRY}
#	${REINPLACE_CMD} '/^@dirrm %%WWWDIR%%\/${dir:C/\//\\\//g}$$/ s|@dirrm|&try|' ${MS_PLIST}
#.endfor
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
