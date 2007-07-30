# New ports collection makefile for:	qstardict
# Date created:		12 Jul 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qstardict
PORTVERSION=	0.05
CATEGORIES=	textproc
MASTER_SITES=	http://qstardict.ylsoftware.com/files/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A StarDict clone written with using Qt4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib qmake uic moc rcc

DICPATH=	${PREFIX}/share/gnome/stardict/dic

PORTDOCS=	AUTHORS COPYNG ChangeLog INSTALL README THANKS

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|g" \
		${WRKSRC}/qstardict.pro
	@${REINPLACE_CMD} -e "s|/usr/share/stardict/dic|${DICPATH}|g" \
		${WRKSRC}/src/dictcore.cpp

post-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS COPYNG ChangeLog INSTALL README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
