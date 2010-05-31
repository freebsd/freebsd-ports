# New ports collection makefile for:	sarg
# Date created:		23.02.2003
# Whom:			mt@primats.org.ua
#
# $FreeBSD$
#

PORTNAME=	sarg
PORTVERSION=	2.2.7.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Squid log analyzer and HTML report generator

OPTIONS=	GD "Enable GD support" on

USE_GCC=	4.2+
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--sysconfdir="${PREFIX}/etc/${PORTNAME}" \
		--enable-sargphp="${PREFIX}/etc/${PORTNAME}" \
		--enable-languagedir="${PREFIX}/etc/${PORTNAME}/languages" \
		--enable-fontdir="${PREFIX}/etc/${PORTNAME}/fonts" \
		--enable-imagedir="${PREFIX}/etc/${PORTNAME}/images"

MAN1=		sarg.1

.include <bsd.port.pre.mk>

.if ${CC} == "cc"
CC=	gcc
.endif

.if !defined(WITHOUT_GD)
GD_PORT?=	graphics/gd
LIB_DEPENDS+=	gd.4:${PORTSDIR}/${GD_PORT}
.endif

.include <bsd.port.post.mk>
