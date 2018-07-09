# $FreeBSD$

PORTNAME=	atompaw
DISTVERSION=	4.1.0.3
CATEGORIES=	science
MASTER_SITES=	http://www.wfu.edu/~natalie/papers/pwpaw/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for projector augmented wave functions for molecular simulations

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	liblapack.so:math/lapack \
		libblas.so:math/blas

OPTIONS_DEFINE=	DOCS

USES=		fortran gmake libtool
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

PLIST_FILES=	bin/atompaw \
		bin/graphatom \
		lib/libatompaw.a

.include <bsd.port.mk>
