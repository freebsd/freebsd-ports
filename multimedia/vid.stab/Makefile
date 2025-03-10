PORTNAME=	vid.stab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	multimedia

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Video stabilization library
WWW=		http://public.hronopik.de/vid.stab/

LICENSE=	GPLv2+

USES=		cmake pathfix
PATHFIX_CMAKELISTSTXT=	create_pkgconfig_file.cmake
USE_GITHUB=	yes
GH_ACCOUNT=	georgmartius
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCPUINFO:STRING="${MACHINE_CPU}"

PORTSCOUT=	skipv:before_complex_transforms

.include <bsd.port.mk>
