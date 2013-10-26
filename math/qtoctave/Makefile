# $FreeBSD$

PORTNAME=	qtoctave
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://forja.rediris.es/frs/download.php/2054/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 frontend for Octave

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

USE_QT4=	designer gui network script svg xml \
		qmake_build moc_build rcc_build uic_build \
		linguist_build
USES=		cmake
CMAKE_ARGS+=	-DWITH_UseRPMTools:Bool=Off

post-patch:
	${REINPLACE_CMD} -e '/COMMAND "lrelease"/s,lrelease,$${QT_LRELEASE_EXECUTABLE},' \
		${WRKSRC}/qtoctave/src/CMakeLists.txt
	${RM} ${WRKSRC}/qtoctave/src/scripts_octave/qtinfo.m.orig

.include <bsd.port.mk>
