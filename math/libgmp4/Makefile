# ex:ts=8
# New ports collection makefile for:	libgmp3
# Date created:			Jan 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgmp
PORTVERSION=	4.1.4
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gmp
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A free library for arbitrary precision arithmetic

USE_LIBTOOL_VER=15
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-cxx --enable-mpfr
INSTALLS_SHLIB=	yes

INFO=		gmp mpfr

post-extract:
	@${RM} -f ${WRKSRC}/gmp.info*

.include <bsd.port.mk>
