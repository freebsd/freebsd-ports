# New ports collection makefile for:	qstardict
# Date created:		12 Jul 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qstardict
PORTVERSION=	0.09
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A StarDict clone written with using Qt4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build uic_build moc_build rcc_build
QMAKE_ARGS+=	 -recursive SEPARATE_TRANSLATIONS=1

DICPATH=	${PREFIX}/share/stardict/dic

PORTDOCS=	AUTHORS COPYNG ChangeLog INSTALL README THANKS

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
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		${WRKSRC}/plugins/stardict/stardict.cpp

do-configure:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-configure:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
