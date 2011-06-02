# New ports collection makefile for:	bird
# Date created:				12th May 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bird
PORTVERSION=	1.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (IPv4 version)

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

OPTIONS=	FIBS		"Enable multiple fib support" Off \
		LEARN_FIX	"Support multiple routing daemons" Off

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	bird

.include <bsd.port.pre.mk>

.if defined(WITH_FIBS)
EXTRA_PATCHES+=	${FILESDIR}/fibs.diff
.endif

.if defined(WITH_LEARN_FIX)
EXTRA_PATCHES+=	${FILESDIR}/learn-krt-sock.c
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/bird.conf ]; then \
		${CP} -p ${PREFIX}/etc/bird.conf.example ${PREFIX}/etc/bird.conf ; \
	fi

.include <bsd.port.post.mk>
