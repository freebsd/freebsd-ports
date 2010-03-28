# New ports collection makefile for:	qstardict
# Date created:		12 Jul 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qstardict
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A StarDict clone written with using Qt4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build uic_build moc_build rcc_build
QMAKE_ARGS+=	-recursive
USE_DOS2UNIX=	qstardict.pri

DICPATH=	${LOCALBASE}/share/stardict/dic

OPTIONS=	DBUS "Enable D-BUS support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
QMAKE_ARGS+=	NO_TRANSLATIONS=1
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_DBUS)
QMAKE_ARGS+=	NO_DBUS=1
.else
LIB_DEPENDS+=	QtDBus.4:${PORTSDIR}/devel/dbus-qt4
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		${WRKSRC}/qstardict.pri
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "/^INSTALLS/s|docs||g" \
		${WRKSRC}/qstardict.pro
.endif
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		${WRKSRC}/plugins/stardict/stardict.cpp

do-configure:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
