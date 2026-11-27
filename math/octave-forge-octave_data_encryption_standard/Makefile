PORTNAME=	octave-forge-octave_data_encryption_standard
DISTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	CNOCTAVE
GH_PROJECT=	octave_data_encryption_standard

post-patch:
	${CHMOD} +x ${WRKSRC}/configure

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
