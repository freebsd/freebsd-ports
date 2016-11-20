# Created by: will
# $FreeBSD$

PORTNAME=	clhep
PORTVERSION=	2.3.1.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://proj-clhep.web.cern.ch/proj-clhep/DISTRIBUTION/tarFiles/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

USES=		cmake:outsource perl5 tar:tgz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
USES+=	compiler:c++11-lib
.else
USES+=	compiler:openmp
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
