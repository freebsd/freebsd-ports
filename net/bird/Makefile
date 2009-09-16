# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird
PORTVERSION=	1.1.3
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Dynamic IP routing daemon

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6

MAKE_JOBS_UNSAFE=	yes

post-install:
	@if [ ! -f ${PREFIX}/etc/bird6.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird6.conf.example ${PREFIX}/etc/bird6.conf ; \
	fi

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800059
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
