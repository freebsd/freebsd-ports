# New ports collection makefile for:	www/drush
# Date created:				April 29th 2010
# Whom:	      				Thomas Sandford <freebsduser@paradisegreen.co.uk>
#
# $FreeBSD$
#

PORTNAME=	drush
PORTVERSION=	3.0
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/
DISTNAME=	drush-All-versions-${PORTVERSION}

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	Drupal command line and scripting interface

NO_BUILD=	yes

# set php requirements same as drupal itself
USE_PHP=	gd pcre session xml mbstring
IGNORE_WITH_PHP=4
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@${REINPLACE_CMD} -e 's|XXXDATADIRXXX|${DATADIR}|g' ${WRKSRC}/drush

do-install:
	${MKDIR} ${DATADIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR} '! ( -name drush -or -name drush.bat -or -name *.orig -or -name *.bak )' )
	${INSTALL_SCRIPT} ${WRKSRC}/drush ${PREFIX}/bin

.include <bsd.port.post.mk>
