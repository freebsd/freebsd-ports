# New ports collection makefile for:	kst
# Date created:			Fri Apr 30 17:28:56 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kst
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	science kde
MASTER_SITES=	SF/${PORTNAME}/Kst%20${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing and plotting tool

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio \
		gsl.15:${PORTSDIR}/math/gsl

LATEST_LINK=	kst2

USE_QT_VER=	4
QT_COMPONENTS=	gui xml designer svg opengl \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

QMAKE_ARGS+=	-unix -recursive
CONFIGURE_ENV+=	INSTALL_PREFIX=${PREFIX}

STRIP_FILES=	bin/kst2 lib/libkst2*.so.1.0.0 lib/kst/libkst2*.so

DESKTOP_ENTRIES=	"Kst 2" \
			"Data viewing and plotting tool" \
			"${PREFIX}/share/pixmaps/kst.png" \
			"kst2" \
			"" \
			false

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 700042
IGNORE=	does not compile on 6.x
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} ${QMAKEFLAGS}

post-configure:
#fix build when Qt-3.x is installed
	${FIND} -d ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		 -e '/^CFLAGS.*=/s|-I/usr/local/include||' \
		 -e '/^CXXFLAGS.*=/s|-I/usr/local/include||'

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/images/kst.png ${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
