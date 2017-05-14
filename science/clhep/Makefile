# Created by: will
# $FreeBSD$

PORTNAME=	clhep
PORTVERSION=	2.3.1.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://proj-clhep.web.cern.ch/proj-clhep/DISTRIBUTION/tarFiles/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BROKEN_powerpc64=	fails to compile: c++11 extension is not available for /usr/bin/c++

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

USES=		cmake:outsource compiler:openmp perl5 tar:tgz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
