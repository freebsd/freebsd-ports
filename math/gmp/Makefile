# ex:ts=8
# New ports collection makefile for:	libgmp3
# Date created:			Jan 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgmp
PORTVERSION=	4.1.2
PORTREVISION=	3
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gmp
DISTNAME=	gmp-${PORTVERSION}

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A free library for arbitrary precision arithmetic

CONFLICTS=	libgmp-2*
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-cxx --enable-mpfr
INSTALLS_SHLIB=	yes

post-extract:
	@rm -f ${WRKSRC}/gmp.info*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e 's|--tag=CC||g'

.include <bsd.port.mk>
