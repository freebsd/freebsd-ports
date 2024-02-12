PORTNAME=	avogadro2
DISTVERSION=	1.99.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical editor and visualization application
WWW=		https://two.avogadro.cc/ # also https://www.openchemistry.org/projects/avogadro2/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	hdf5>0:science/hdf5
LIB_DEPENDS=	libAvogadroCore.so:science/avogadrolibs \
		libMoleQueueClient.so:misc/molequeue
RUN_DEPENDS=	obabel:science/openbabel

USES=		cmake compiler:c++11-lang desktop-file-utils gl libarchive qt:5
USE_QT=		core concurrent gui network widgets buildtools:build qmake:build
USE_GL=		gl glew glu

USE_GITHUB=	yes
GH_ACCOUNT=	OpenChemistry
GH_PROJECT=	avogadroapp
GH_TUPLE=	flathub:shared-modules:1bb5393:flathub_shared_modules/flatpak/shared-modules \
		openchemistry:avogadro-i18n:16142cf:i18n/../avogadro-i18n

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
