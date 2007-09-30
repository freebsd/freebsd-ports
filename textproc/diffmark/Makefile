# New ports collection makefile for:	diffmark
# Date created:	   05 September 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	diffmark
PORTVERSION=	0.05
CATEGORIES=	textproc
MASTER_SITES=	http://www.mangrove.cz/diffmark/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	XML diff and merge package

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-libxml2-incldir=${LOCALBASE}/include/libxml2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
