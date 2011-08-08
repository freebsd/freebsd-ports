# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird6
PORTVERSION=	1.3.2
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/
DISTNAME=	bird-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv6 version)

LICENSE=	GPLv2

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6

OPTIONS=	CONFIG_INCLUDES	"Permit config 'include' keyword" Off

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird6

.if defined(WITH_CONFIG_INCLUDES)
EXTRA_PATCHES+=	${FILESDIR}/extra-config_includes.diff
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/bird6.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird6.conf.example ${PREFIX}/etc/bird6.conf ; \
	fi

.include <bsd.port.mk>
