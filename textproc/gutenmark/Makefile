# Created by: ijliao
# $FreeBSD$

PORTNAME=	gutenmark
PORTVERSION=	20090510
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	http://www.sandroid.org/GutenMark/wasftp.GutenMark/SoftwareSnapshots/
DISTNAME=	GutenMark_source_dev-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Attractively formatting Project Gutenberg texts

WRKSRC=		${WRKDIR}/GutenMark-source

USES=		compiler:c++11-lib gmake
USE_CXXSTD=	c++11
USE_WX=		3.0
ALL_TARGET=	default

PLIST_FILES=	bin/GutenMark bin/GutenSplit bin/GUItenMark \
		%%DATADIR%%/convert.jpg %%DATADIR%%/logo.jpg

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|g ; \
		 s|-O3|${CFLAGS}|g ; \
		 /strip /d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall|${CFLAGS} -Wall|g ; \
		 /strip /d' ${WRKSRC}/GutenUtilities/Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX} ${CXXFLAGS}|g ; \
		 s|`wx-config|`${WX_CONFIG}|g ; \
		 /strip /d' ${WRKSRC}/GUItenMark/Makefile
	@${REINPLACE_CMD} -e 's|\./convert.jpg|${DATADIR}/convert.jpg|g ; \
		 s|\./logo.jpg|${DATADIR}/logo.jpg|g' ${WRKSRC}/GUItenMark/GUItenMark.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GutenUtilities/GutenSplit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GUItenMark/GUItenMark ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GUItenMark/*.jpg ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
