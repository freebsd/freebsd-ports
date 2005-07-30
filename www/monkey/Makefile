# New ports collection makefile for:	monkey
# Date created:				Mon Oct 20 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	monkey
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	http://monkeyd.sourceforge.net/versions/

MAINTAINER=	az@inec.ru
COMMENT=	A small, powerful, and fast Web server written in C

USE_GMAKE=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/sbin \
		--cgibin=${PREFIX}/www/cgi-bin \
		--sysconfdir=${PREFIX}/etc/monkey \
		--datadir=${PREFIX}/www/data \
		--logdir=/var/log \
		--lang=en

CONFIGURE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/monkey.sh ${PREFIX}/etc/rc.d/monkey.sh.sample

.include <bsd.port.post.mk>
