# ex:ts=8
# New ports collection makefile for:	txt2man
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2man
PORTVERSION=	1.4.5
CATEGORIES=	textproc
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Converts flat ASCII text to man page format

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	${BUILD_DEPENDS}

ALL_TARGET=	txt2man.1
INSTALL_TARGET=	install prefix=${PREFIX}

MAN1=	txt2man.1

.include <bsd.port.mk>
