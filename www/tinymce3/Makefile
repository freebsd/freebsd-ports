# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	tinymce
PORTVERSION=	3.5.8
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

LICENSE=	LGPL21

CONFLICTS_INSTALL=	tinymce-[0-24-9]*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@${TOUCH} \
	  	${WRKSRC}/jscripts/tiny_mce/plugins/spellchecker/classes/utils/.keepme \
		${WRKSRC}/jscripts/tiny_mce/plugins/spellchecker/includes/.keepme

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

# maintainer section:

#MS_DIRRMTRY=	# empty
MS_EMPTYDIRS=	${WRKDIR}/.ms-empty-directories
MS_PLIST=	${WRKDIR}/.ms-pkg-plist

genplist: do-clean extract
	cd ${WRKSRC}/ && \
		${FIND} -s * -type d -empty | ${XARGS} > ${MS_EMPTYDIRS} && \
		${SED} 's|[^ ]*|&/.keepme|g' ${MS_EMPTYDIRS} | ${XARGS} -J % ${TOUCH} % && \
		${FIND} -s * -type f | ${SED} 's|^|%%WWWDIR%%/|' > ${MS_PLIST} && \
		${FIND} -s * -type d | ${TAIL} -r | ${SED} 's|^|@dirrm %%WWWDIR%%/|' >> ${MS_PLIST} && \
		${ECHO} '@dirrmtry %%WWWDIR%%' >> ${MS_PLIST}
#.for dir in ${MS_DIRRMTRY}
#	${REINPLACE_CMD} '/^@dirrm %%WWWDIR%%\/${dir:C/\//\\\//g}$$/ s|@dirrm|&try|' ${MS_PLIST}
#.endfor
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}
	${REINPLACE_CMD} -e "/^EMPTYDIRS=/ s|	.*$$|	`${CAT} ${MS_EMPTYDIRS}`|" ${.CURDIR}/Makefile

.include <bsd.port.mk>
