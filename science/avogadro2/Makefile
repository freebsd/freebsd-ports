PORTNAME=	avogadro2
DISTVERSION=	1.95.1
PORTREVISION=	1
CATEGORIES=	science

# REGRESSION: https://github.com/OpenChemistry/avogadroapp/issues/191

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical editor and visualization application

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hdf5>0:science/hdf5
LIB_DEPENDS=	libAvogadroCore.so:science/avogadrolibs \
		libMoleQueueClient.so:misc/molequeue

USES=		cmake compiler:c++11-lang desktop-file-utils gl libarchive qt:5
USE_QT=		core concurrent gui network widgets buildtools_build qmake_build
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
GH_PROJECT=	avogadroapp
GH_TUPLE=	flathub:shared-modules:a79072c:flathub_shared_modules/flatpak/shared-modules \
		openchemistry:avogadro-i18n:3b8a86c:i18n/../avogadro-i18n

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
