# New ports collection makefile for:    qd
# Date created:                         2007/03/28
# Whom:                                 Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qd
PORTVERSION=	2.3.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.berkeley.edu/~yozo/software/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Double-Double and Quad-Double Arithmetic

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--enable-shared=yes

.include <bsd.port.post.mk>
