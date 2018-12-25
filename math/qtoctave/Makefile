# $FreeBSD$

PORTNAME=	qtoctave
PORTVERSION=	0.10.1
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://forja.rediris.es/frs/download.php/2054/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 frontend for Octave

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	octave:math/octave

USE_QT=		designer gui network script svg xml \
		qmake_build moc_build rcc_build uic_build \
		linguisttools_build
USES=		cmake:insource qt:4
CMAKE_ARGS+=	-DWITH_UseRPMTools:Bool=Off

post-patch:
	${REINPLACE_CMD} -e '/COMMAND "lrelease"/s,lrelease,$${QT_LRELEASE_EXECUTABLE},' \
		${WRKSRC}/qtoctave/src/CMakeLists.txt
	${RM} ${WRKSRC}/qtoctave/src/scripts_octave/qtinfo.m.orig

.include <bsd.port.mk>
