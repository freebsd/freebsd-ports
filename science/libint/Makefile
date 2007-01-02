# New ports collection makefile for:	libint
# Date created:				29 Dec 2006
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libint
PORTVERSION=	1.1.2
PORTREVERSION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.ccmst.gatech.edu/evaleev/libint/src/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

USE_PERL5=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	# empty

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared

.include <bsd.port.post.mk>
