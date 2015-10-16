# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zen-cart
PORTVERSION=	1.3.9h
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.akherb.com/FreeBSD/source/ \
		LOCAL/beech
DISTNAME=	zen-cart-v1.3.9h-full-fileset-10262010

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP-based user-friendly, open source shopping cart

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt
USES=		dos2unix shebangfix zip
SHEBANG_FILES=	editors/htmlarea/examples/2-areas.cgi \
		editors/htmlarea/examples/test.cgi \
		editors/htmlarea/plugins/SpellChecker/spell-check-logic.cgi
USE_PHP=	yes
WANT_PHP_WEB=	yes
DOS2UNIX_REGEX=	.*\.php

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR="${WWWDIR}" PORTNAME="${PORTNAME}"
PLIST_SUB+=	WWWDIR=${WWWDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} PORTNAME=${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${EXAMPLESDIR} && ${RM} -rf ${WRKSRC}/docs)
	(cd ${WRKSRC} && ${MV} vbv_learn_more.html ${STAGEDIR}${EXAMPLESDIR}/)
	(cd ${WRKSRC} && ${MV} mcs_learn_more.html ${STAGEDIR}${EXAMPLESDIR}/)
	(cd ${WRKSRC} && ${MV} robots_example.txt ${STAGEDIR}${EXAMPLESDIR}/)
	(cd ${WRKSRC} && ${MV} install.txt ${STAGEDIR}${EXAMPLESDIR}/)
	(cd ${WRKSRC} && ${MV} nddbc.html ${STAGEDIR}${EXAMPLESDIR}/)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/)
	${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
