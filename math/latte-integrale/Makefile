# $FreeBSD$

PORTNAME=	latte-integrale
DISTVERSIONPREFIX=	version_
DISTVERSION=	1_7_6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for counting lattice points/integration over convex polytopes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lrs:math/lrslib \
		points2triangs:math/topcom
LIB_DEPENDS=	lib4ti2util.so:math/4ti2 \
		libcddgmp.so:math/cddlib \
		libgmp.so:math/gmp \
		libntl.so:math/ntl
RUN_DEPENDS=	lrs:math/lrslib \
		points2triangs:math/topcom

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-topcom=${LOCALBASE} --with-4ti2=${LOCALBASE} --with-cddlib=${LOCALBASE} --with-gmp=${LOCALBASE} --with-ntl=${LOCALBASE}
USE_GITHUB=	yes
GH_ACCOUNT=	latte-int
GH_PROJECT=	latte
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	latte

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.mk>
