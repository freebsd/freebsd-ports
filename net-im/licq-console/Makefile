# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ncurses-based console plugin for Licq

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"
LICQ_PORT?=	net/licq

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
