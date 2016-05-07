# Created by: CHOI Junho <cjh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicfilter
PORTVERSION=	2.3.h
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/magicfilter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable, extensible automatic printer filter

USES=		ghostscript

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--confdir=${PREFIX}/etc \
			--filterdir=${PREFIX}/libexec/magicfilter \
			--use-fifo
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

.if exists(${LOCALBASE}/lib/libmagic.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmagic.so:sysutils/file
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.include <bsd.port.mk>
