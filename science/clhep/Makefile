PORTNAME=	clhep
PORTVERSION=	2.4.7.1
CATEGORIES=	science math
MASTER_SITES=	https://proj-clhep.web.cern.ch/proj-clhep/dist1/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN
WWW=		https://proj-clhep.web.cern.ch/proj-clhep/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		cmake:testing compiler:c++11-lang perl5 tar:tgz
USE_LDCONFIG=	yes
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
