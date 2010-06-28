# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird6
PORTVERSION=	1.2.3
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/
DISTNAME=	bird-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Dynamic IP routing daemon (IPv6 version)

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird6

post-install:
	@if [ ! -f ${PREFIX}/etc/bird6.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird6.conf.example ${PREFIX}/etc/bird6.conf ; \
	fi

.include <bsd.port.mk>
