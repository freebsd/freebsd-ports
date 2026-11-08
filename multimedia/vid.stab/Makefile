PORTNAME=	vid.stab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	multimedia

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Video stabilization library
WWW=		https://github.com/georgmartius/vid.stab

# Future releases will be LGPL2.1+ (https://github.com/georgmartius/vid.stab/blob/master/RELICENSE.md)
LICENSE=	GPLv2+

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	georgmartius
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCPUINFO:STRING="${MACHINE_CPU}"

PORTSCOUT=	skipv:before_complex_transforms

.include <bsd.port.mk>
