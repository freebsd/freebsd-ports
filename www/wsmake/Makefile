# New ports collection makefile for: wsmake
# Date created:        31 May, 2002
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wsmake
PORTVERSION=	0.7.901
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Software for production and maintenance of web sites

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gwsmake=no --enable-iswmake=no

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--enable-docs=no
.else
INFO=	wsmake iwsmake gwsmake
MAN1=	wsmake.1
.endif

.include <bsd.port.post.mk>
