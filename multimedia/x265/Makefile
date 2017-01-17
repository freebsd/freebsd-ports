# Created by: adamw
# $FreeBSD$

PORTNAME=	x265
PORTVERSION=	2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://bitbucket.org/multicoreware/${PORTNAME}/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	yasm:devel/yasm

USES=		cmake pathfix tar:bz2
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_TESTS=on -DPLATFORM_LIBS=md
EXTRACT_AFTER_ARGS+=	--exclude "md5*"

WRKSRC=		${WRKDIR}/multicoreware-${PORTNAME}-be14a7e9755e/source

BROKEN_mips64=		Fails to link: Nonrepresentable section on output

do-test:
	${WRKSRC}/test/TestBench

.include <bsd.port.mk>
