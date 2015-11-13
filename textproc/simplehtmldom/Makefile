# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	simplehtmldom
DISTVERSION=	1.5
PORTEPOCH=	1
CATEGORIES=	textproc www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME=	${PORTNAME}_${DISTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP Simple HTML DOM Parser

BROKEN=		unfetchable
DEPRECATED=	PHP 5.4 EOL reached
EXPIRATION_DATE=	2016-01-15

USES=		zip
NO_BUILD=	yes
NO_WRKSRC=	yes

USE_PHP=	pcre
DEFAULT_PHP_VER=	5

SUB_FILES+=	pkg-message
SUB_LIST+=	DATADIR=${DATADIR} PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${FIND} ${WRKDIR} -name .svn -type d | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR} && ${INSTALL} -c -m 644 simple_html_dom.php \
		change_log.txt ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "app testcase" \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/manual && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
