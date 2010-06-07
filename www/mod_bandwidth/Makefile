# New ports collection makefile for:	mod_bandwidth
# Date created:				2 July 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

#Orignal locations: ftp://ftp.cohprog.com/pub/apache/module/1.3.0/mod_bandwidth.c
#                   ftp://ftp.cohprog.com/pub/apache/module/cleanlink.pl

PORTNAME=	mod_bandwidth
PORTVERSION=	2.1.0
CATEGORIES=	www
MASTER_SITES=	http://potatohead.estat.com/FreeBSD/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Bandwidth management module for the Apache webserver

MAKE_JOBS_SAFE=	yes

CONFLICTS=	apache-contrib-1.*

USE_PERL5=	YES
USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PLIST_FILES+=	sbin/cleanlink.pl

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cleanlink.pl ${LOCALBASE}/sbin
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
