PORTNAME=	optench
DISTVERSION=	1.2.5
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Virtual optical bench
WWW=		https://amini-allight.org/optench

LICENSE=	GPLv3

USES=		cmake compiler:c++20-lang desktop-file-utils gl localbase	\
		qt:6 shared-mime-info tar:bz2
USE_GL=		egl opengl
USE_QT=		base
LDFLAGS+=	-L${QT_LIBDIR}

USE_GITLAB=	yes
GL_ACCOUNT=	amini-allight

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DOPTENCH_DEPLOYMENT:BOOL=OFF
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/include/qt6|${QT_INCDIR}|'	\
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
