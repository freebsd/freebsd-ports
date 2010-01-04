# New ports collection makefile for:	mythweb
# Date created:		2009-12-27
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	mythweb
PORTVERSION=	0.22
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
DISTNAME=	mythplugins-${PORTVERSION}

MAINTAINER=	decke@bluelife.at
COMMENT=	A frontend for scheduling and managing recordings on your MythTV Box

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

NO_BUILD=	yes
USE_BZIP2=	yes
USE_APACHE=	2.2+
USE_PHP=	spl session mysql pcre posix json
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html|${WWWDIR}|' \
		${WRKSRC}/mythweb/mythweb.conf.apache

do-install:
	${MKDIR} ${WWWDIR}
	${MKDIR} ${WWWDIR}/data
	(cd ${WRKSRC}/mythweb/ && ${COPYTREE_SHARE} "*" ${WWWDIR} "! -name *.bak")

	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} -R 775 ${WWWDIR}/data

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
