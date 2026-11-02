PORTNAME=	iboview
DISTVERSION=	20260917
CATEGORIES=	science
MASTER_SITES=	http://www.iboview.org/bin/
DISTNAME=	ibo-view.20211019-RevA

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for analyzing molecular electronic structure
WWW=		http://www.iboview.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
RUN_DEPENDS=	boost-libs>=0:devel/boost-libs

USES=		blaslapack:openblas fortran gl qmake:outsource qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	KoehnLab
GH_TAGNAME=	500054ed80d12aa1f52f498520e543c5c837e26c

USE_CXXSTD=	c++20
USE_GL=		gl
USE_QT=		base declarative svg

CONFIGURE_ENV=	BLASLIB="${BLASLIB}" \
		BOOST_ROOT=${LOCALBASE}/include
QMAKE_ARGS=	DEFINES+=_I4_ DEFINES+=GLEW_NO_GLU

PLIST_FILES=	bin/iboview

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/iboview ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
