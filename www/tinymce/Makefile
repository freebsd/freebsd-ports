# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	4.0.10
CATEGORIES=	www
MASTER_SITES=	http://download.moxiecode.com/${PORTNAME}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

LICENSE=	LGPL21

CONFLICTS_INSTALL=	tinymce-[0-35-9]* tinymce3-[0-9]*

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

#MS_DIRRMTRY=	# empty
MS_EMPTYDIRS=	${WRKDIR}/.ms-empty-directories
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	cd ${WRKSRC}/ && \
		${FIND} -s * -type d -empty | ${XARGS} >> ${MS_EMPTYDIRS} && \
		${SED} 's|[^ ]*|&/.keepme|g' ${MS_EMPTYDIRS} | ${XARGS} -J % ${TOUCH} % && \
		${ECHO} "@owner www" > ${MS_PLIST} && \
		${ECHO} "@group www" >> ${MS_PLIST} && \
		${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' >> ${MS_PLIST} && \
		${FIND} -s * -type d | ${TAIL} -r | ${SED} 's|^|@dirrm %%WWWDIR%%/|' >> ${MS_PLIST} && \
		${ECHO} '@dirrmtry %%WWWDIR%%' >> ${MS_PLIST}
#.for dir in ${MS_DIRRMTRY}
#	${REINPLACE_CMD} '/^@dirrm %%WWWDIR%%\/${dir:C/\//\\\//g}$$/ s|@dirrm|&try|' ${MS_PLIST}
#.endfor
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}
	${REINPLACE_CMD} -e "/^EMPTYDIRS=/ s|	.*$$|	`${CAT} ${MS_EMPTYDIRS}`|" ${.CURDIR}/Makefile

.include <bsd.port.mk>
