PORTNAME=	clhep
DISTVERSION=	2.4.7.2
CATEGORIES=	science math
MASTER_SITES=	https://proj-clhep.web.cern.ch/proj-clhep/dist1/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN
WWW=		https://proj-clhep.web.cern.ch/proj-clhep/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		cmake:testing compiler:c++11-lang perl5 tar:tgz
USE_GITLAB=	yes
GL_SITE=	https://gitlab.cern.ch
GL_ACCOUNT=	${PORTNAME:tu}
GL_PROJECT=	${PORTNAME:tu}
GL_TAGNAME=	${PORTNAME:tu}_${DISTVERSION:S/./_/g}
USE_LDCONFIG=	yes
USE_PERL5=	build

PLIST_SUB=	VERSION="${DISTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
