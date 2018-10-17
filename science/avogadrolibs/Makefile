# $FreeBSD$

PORTNAME=	avogadrolibs
DISTVERSION=	1.91.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Avogadro2 libraries for chemical editor and visualization applications

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp \
		libMoleQueueClient.so:misc/molequeue \
		libmsym.so:science/libmsym \
		libsymspg.so:science/spglib

USES=		cmake:outsource compiler:c++11-lang eigen:3,build,run gl libarchive qt:5 # eigen needs to be 'run' because it is written into cmake files
USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
USE_QT=		core concurrent gui network widgets buildtools_build qmake_build
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
