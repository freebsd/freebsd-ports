# New ports collection makefile for: arora
# Date created:         08 Aug 2008
# Whom:                 Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	arora
PORTVERSION=	0.7.1
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	decept0@gmail.com
COMMENT=	Simple Qt4 based browser

USE_QT_VER=	4
QT_COMPONENTS=	network webkit qmake_build moc_build uic_build rcc_build \
		imageformats gui script sql
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix -recursive PREFIX=${PREFIX}
MAKE_JOBS_SAFE=	yes

MAN1=	arora.1

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.endif

do-configure:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "/INSTALLS/s|translations||" \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e "s|target_predeps||" \
		${WRKSRC}/src/locale/locale.pri
.endif
	@${REINPLACE_CMD} -e "/INSTALLS/s|man man-compress||" \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e "/else/s|lrelease|lrelease-qt4|" \
		${WRKSRC}/src/locale/locale.pri
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	@${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|' \
		${WRKSRC}/src/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/data/arora.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
