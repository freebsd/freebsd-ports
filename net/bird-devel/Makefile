# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
PORTVERSION=	20130301
CATEGORIES=	net
MASTER_SITES=	http://bird.mpls.in/distfiles/bird/
PKGNAMESUFFIX=	-devel

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (devel version)

CONFLICTS=	bird-[0-9]*

USES=		bison gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --enable-mpls
USE_CSTD=	gnu89

OPTIONS_DEFINE=	KMPLS
KMPLS_DESC=	kernel MPLS support

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

KMPLS_CONFIGURE_ON=	--enable-kmpls

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}
	@${ECHO_MSG} "        WARNING: Please take a look on kern/134931"
	@${ECHO_MSG} "        WARNING: before using multiple fibs!"
	@${ECHO_MSG} "        8.2-STABLE kernel patch available here:"
	@${ECHO_MSG} "        http://static.ipfw.ru/patches/rtsock_82S-20110725.diff"
	@${ECHO_MSG}
	@${ECHO_MSG} =====================================================================
	@${ECHO_MSG}

.include <bsd.port.mk>
