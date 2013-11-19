# Created by: Lukasz Stelmach <lukasz.stelmach@iem.pw.edu.pl>
# $FreeBSD$

PORTNAME=	MathJax
PORTVERSION=	2.2
CATEGORIES=	www

MAINTAINER=	lukasz.stelmach@iem.pw.edu.pl
COMMENT=	Cross-browser JavaScript display engine for mathematics

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	mathjax
GH_TAGNAME=	v${PORTVERSION}

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-54280bb

# Changing permissions of 30k files with find -exec (COPYTREE) is way
# too slow.
do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${FIND} -d . | ${CPIO} -dumpl ${STAGEDIR}${WWWDIR} >/dev/null 2>&1)
	${FIND} -d ${STAGEDIR}${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} -d ${STAGEDIR}${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${STAGEDIR}${WWWDIR}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s ${WWWDIR_REL} -not -type d) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s -d ${WWWDIR_REL} -type d) \
	| ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
