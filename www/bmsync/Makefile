# New ports collection makefile for:	bmsync
# Date created:				22 Sep 2000
# Whom:					Dan Pelleg <dpelleg+bmsync@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	bmsync
PORTVERSION=	0.2.0
CATEGORIES=	www
MASTER_SITES=	http://www.cs.cmu.edu/~dpelleg/sw/

MAINTAINER=	dpelleg+bmsync@cs.cmu.edu

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		bmsync.1
MAN_COMPRESSED=	no

pre-install:
	@${PERL} -pi -e "s:/usr/bin/perl:${PERL}:g" ${WRKSRC}/bmsync

.include <bsd.port.mk>
