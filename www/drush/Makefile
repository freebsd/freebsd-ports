# Created by: Thomas Sandford <freebsduser@paradisegreen.co.uk>
# $FreeBSD$

PORTNAME=	drush
PORTVERSION=	6.5.0
CATEGORIES=	www

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Drupal command line and scripting interface

LICENSE=	GPLv2

RUN_DEPENDS=	pear-Console_Table>0:devel/pear-Console_Table

NO_BUILD=	yes

GH_ACCOUNT=	${PORTNAME}-ops
USE_GITHUB=	yes

# set php requirements same as drupal itself
USE_PHP=	gd pcre session mbstring ctype json hash simplexml dom pdo filter
WANT_PHP_CLI=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-configure:
	@${REINPLACE_CMD} -e 's|XXXDATADIRXXX|${STAGEDIR}${DATADIR}|g' ${WRKSRC}/drush

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	( cd ${WRKSRC} && \
	${COPYTREE_SHARE} "classes commands includes lib misc tests drush_logo-black.png drush.php drush.info" ${STAGEDIR}${DATADIR} && \
	${INSTALL_DATA} drush_logo-black.png drush.php ${STAGEDIR}${DATADIR} && \
	${INSTALL_SCRIPT} drush drush.complete.sh ${STAGEDIR}${DATADIR} )
	${LN} -s ${DATADIR}/drush ${STAGEDIR}${PREFIX}/bin/drush
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_MAN} *.md docs/* ${STAGEDIR}${DOCSDIR} )
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC} && ${INSTALL_MAN} examples/* ${STAGEDIR}${EXAMPLESDIR} )

.include <bsd.port.mk>
