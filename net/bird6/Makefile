# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird6
PORTVERSION=	1.3.11
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/ \
		http://bird.mpls.in/distfiles/bird/
DISTNAME=	bird-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv6 version)

LICENSE=	GPLv2

USES=		bison
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ipv6 --localstatedir=/var
USE_CSTD=	gnu89

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird6

post-install:
	@if [ ! -f ${PREFIX}/etc/bird6.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird6.conf.example ${PREFIX}/etc/bird6.conf ; \
	fi

.include <bsd.port.mk>
