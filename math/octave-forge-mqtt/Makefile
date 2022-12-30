PORTNAME=	octave-forge-mqtt
PORTVERSION=	0.0.3
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=octave-mqtt/v${PORTVERSION}
DISTNAME=	octave-${OCTAVE_PKGNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libpaho-mqtt3a.so:net/libpaho-mqtt3

USES=		autoreconf localbase octave

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
