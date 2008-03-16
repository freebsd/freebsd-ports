# New ports collection makefile for:	qstardict
# Date created:		12 Jul 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qstardict
PORTVERSION=	0.08
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A StarDict clone written with using Qt4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib qmake_build uic_build moc_build rcc_build

DICPATH=	${PREFIX}/share/stardict/dic

PORTDOCS=	AUTHORS COPYNG ChangeLog INSTALL README THANKS

OPTIONS=	DBUS "Enable D-BUS support" on

.include <bsd.port.pre.mk>
.if defined(WITHOUT_NLS)
QMAKE_ARGS+=	NO_TRANSLATIONS=1
.endif

.if defined(WITHOUT_DBUS)
QMAKE_ARGS+=	NO_DBUS=1
.else
#QMAKE_ARGS+=	"CONFIG+=qdbus"
LIB_DEPENDS+=	QtDBus.4:${PORTSDIR}/devel/dbus-qt4
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		${WRKSRC}/qstardict.pro
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		${WRKSRC}/src/dictcore.cpp

post-configure:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS COPYNG ChangeLog INSTALL README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
