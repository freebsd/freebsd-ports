# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org

USE_AUTOMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
INCDIR=		${PORTSDIR}/net

.include <bsd.port.pre.mk>
.if defined(WITH_LICQ_DEVEL)
.include "${INCDIR}/licq-devel/Makefile.inc"
.else
.include "${INCDIR}/licq/Makefile.inc"
.endif
.include <bsd.port.post.mk>
