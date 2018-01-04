# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
DISTVERSION=	2.0.0-pre1
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/ \
		http://bird.mpls.in/distfiles/bird/
PKGNAMESUFFIX=	-devel

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (devel version)

CONFLICTS=	bird-[0-9]*

USES=		bison gmake readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_CSTD=	gnu89

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

.include <bsd.port.mk>
