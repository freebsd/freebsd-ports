# New ports collection makefile for:   cassowary
# Date created:        01 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD>org>
#
# $FreeBSD$
#

PORTNAME=	cassowary
PORTVERSION=	0.60
CATEGORIES=	misc
MASTER_SITES=	http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	GTL.3:${PORTSDIR}/misc/gtl

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-guile-prefix=${LOCALBASE} \
		--enable-guile-build \
		--enable-permissive
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_BISON=	yes

.include <bsd.port.mk>
