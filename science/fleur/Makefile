# $FreeBSD$

PORTNAME=	fleur
DISTVERSION=	0.27-3 # Release 3 of Version 0.27
CATEGORIES=	science
MASTER_SITES=	http://www.flapw.de/pm/uploads/FLEUR/
DISTNAME=	fleurMaXR${DISTVERSION:C/.*-//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FLAPW code for atomic computations in quantum chemistry and physics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:outsource,noninja fortran localbase:ldflags tar:tgz
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/fleur \
		bin/inpgen

.include <bsd.port.mk>
