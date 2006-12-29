# New ports collection makefile for:	libint
# Date created:				29 Dec 2006
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libint
PORTVERSION=	1.1.2
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

post-install:
	@${MV} ${PREFIX}/lib/libderiv-stable.so ${PREFIX}/lib/libderiv.so
	@${MV} ${PREFIX}/lib/libderiv-stable.so.1 ${PREFIX}/lib/libderiv.so.1
	@${MV} ${PREFIX}/lib/libint-stable.so ${PREFIX}/lib/libint.so
	@${MV} ${PREFIX}/lib/libint-stable.so.1 ${PREFIX}/lib/libint.so.1
	@${MV} ${PREFIX}/lib/libr12-stable.so ${PREFIX}/lib/libr12.so
	@${MV} ${PREFIX}/lib/libr12-stable.so.1 ${PREFIX}/lib/libr12.so.1

.include <bsd.port.post.mk>
