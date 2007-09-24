# New ports collection makefile for:	magicfilter
# Date created:		24 Mar 1999
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	magicfilter
PORTVERSION=	2.3.h
PORTREVISION=	1
PORREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/magicfilter/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Customizable, extensible automatic printer filter

BUILD_DEPENDS=	${LOCALBASE}/lib/libmagic.so:${PORTSDIR}/sysutils/file
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GHOSTSCRIPT=	yes

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--confdir=${PREFIX}/etc \
			--filterdir=${PREFIX}/libexec/magicfilter \
			--use-fifo
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
MAN5=		magicfilter.5
MAN8=		magicfilter.8

.include <bsd.port.mk>
