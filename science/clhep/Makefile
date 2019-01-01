# Created by: will
# $FreeBSD$

PORTNAME=	clhep
PORTVERSION=	2.4.1.0
CATEGORIES=	science
MASTER_SITES=	http://proj-clhep.web.cern.ch/proj-clhep/DISTRIBUTION/tarFiles/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		cmake compiler:c++11-lang perl5 tar:tgz

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
