# New ports collection makefile for:	mod_bandwidth
# Date created:				2 July 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_bandwidth
PORTVERSION=	2.0.5
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/
#Orignal locations: ftp://ftp.cohprog.com/pub/apache/module/1.3.0/mod_bandwidth.c
#                   ftp://ftp.cohprog.com/pub/apache/module/cleanlink.pl
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth management module for the Apache webserver

USE_APACHE=	YES
USE_PERL5=	YES

CONFLICTS=	apache-contrib-1.*

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.so)
	@${INSTALL_SCRIPT} ${WRKSRC}/cleanlink.pl ${LOCALBASE}/sbin
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
