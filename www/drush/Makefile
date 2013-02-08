# Created by: Thomas Sandford <freebsduser@paradisegreen.co.uk>
# $FreeBSD$

PORTNAME=	drush
PORTVERSION=	5.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drush-7.x-${PORTVERSION}

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Drupal command line and scripting interface

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/pear/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

NO_BUILD=	yes

# set php requirements same as drupal itself
USE_PHP=	gd pcre session xml mbstring ctype json hash simplexml dom pdo pdo_mysql
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
