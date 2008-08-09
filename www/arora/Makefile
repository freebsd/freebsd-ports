# New ports collection makefile for: arora
# Date created:         08 Aug 2008
# Whom:                 Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	arora
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	andy@athame.co.uk
COMMENT=	Simple Qt4 based browser

USE_QT_VER=	4
QT_COMPONENTS=	network webkit qmake_build moc_build uic_build rcc_build
HAS_CONFIGURE=	yes
QMAKE_ARGS+=	-unix -recursive PREFIX=${PREFIX}

MAN1=	arora.1

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-configure:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "/INSTALLS/s|translations||" \
		-e "/PRE_TARGETDEPS/s|compiler_updateqm_make_all||" \
		${WRKSRC}/src/src.pro
.endif
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/data/arora.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
