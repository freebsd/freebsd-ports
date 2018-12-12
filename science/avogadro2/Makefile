# $FreeBSD$

PORTNAME=	avogadro2
DISTVERSION=	1.91.0
PORTREVISION=	2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical editor and visualization application

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hdf5>0:science/hdf5
LIB_DEPENDS=	libAvogadroCore.so:science/avogadrolibs \
		libMoleQueueClient.so:misc/molequeue

USES=		cmake:outsource compiler:c++11-lang desktop-file-utils gl libarchive qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
GH_PROJECT=	avogadroapp
USE_QT=		core concurrent gui network widgets buildtools_build qmake_build
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

PLIST_FILES=	bin/avogadro2 \
		share/applications/avogadro2.desktop \
		share/pixmaps/avogadro2.png

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
