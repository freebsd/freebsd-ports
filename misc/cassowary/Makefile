# New ports collection makefile for:   cassowary
# Version required:    0.55
# Date created:        01 October 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD>org>
#
# $FreeBSD$
#

DISTNAME=	cassowary-0.55
CATEGORIES=	misc
MASTER_SITES=	http://www.cs.washington.edu/research/constraints/cassowary/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	GTL.3:${PORTSDIR}/misc/gtl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-guile-prefix=${LOCALBASE} \
		--enable-guile-build \
		--enable-permissive
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_BISON=	yes

.include <bsd.port.mk>
