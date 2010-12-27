# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird
PORTVERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Dynamic IP routing daemon (IPv4 version)

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

post-install:
	@if [ ! -f ${PREFIX}/etc/bird.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird.conf.example ${PREFIX}/etc/bird.conf ; \
	fi

.include <bsd.port.mk>
