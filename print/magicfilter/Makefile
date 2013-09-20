# Created by: CHOI Junho <cjh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magicfilter
PORTVERSION=	2.3.h
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.pell.portland.or.us/~orc/Code/magicfilter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable, extensible automatic printer filter

USE_GHOSTSCRIPT=	yes

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--confdir=${PREFIX}/etc \
			--filterdir=${PREFIX}/libexec/magicfilter \
			--use-fifo
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
MAN5=		magicfilter.5
MAN8=		magicfilter.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libmagic.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmagic.so:${PORTSDIR}/sysutils/file
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
