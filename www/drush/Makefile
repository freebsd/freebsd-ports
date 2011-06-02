# New ports collection makefile for:	www/drush
# Date created:				April 29th 2010
# Whom:	      				Thomas Sandford <freebsduser@paradisegreen.co.uk>
#
# $FreeBSD$
#

PORTNAME=	drush
PORTVERSION=	4.4
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drush-7.x-${PORTVERSION}

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Drupal command line and scripting interface

RUN_DEPENDS=	${LOCALBASE}/share/pear/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_BUILD=	yes

# set php requirements same as drupal itself
USE_PHP=	gd pcre session xml mbstring ctype
IGNORE_WITH_PHP=4
WANT_PHP_CLI=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@${REINPLACE_CMD} -e 's|XXXDATADIRXXX|${DATADIR}|g' ${WRKSRC}/drush

do-install:
	${MKDIR} ${DATADIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR} '! ( -name drush.bat -or -name *.orig -or -name *.bak -or -name .gitignore -or -name LICENSE.txt )' )
	${CHMOD} 755 ${DATADIR}/drush
	${LN} -s ${DATADIR}/drush ${PREFIX}/bin/drush

.include <bsd.port.post.mk>
