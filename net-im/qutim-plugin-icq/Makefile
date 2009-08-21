# New ports collection makefile for:	qutim-plugin-icq
# Date created:		Thu Jan 16 12:00:00 MSK 2008
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	icq
PORTVERSION=	0.2b
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/download/ \
		http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
PKGNAMEPREFIX=	qutim-plugin-
DISTNAME=	qutim-icq_${PORTVERSION}_svn71

MAINTAINER=	webmaster@kibab.com
COMMENT=	ICQ protocol plugin for qutIM

BUILD_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim
RUN_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build

WRKSRC=		${WRKDIR}/icq

pre-build:
	cd ${WRKDIR}/icq && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	@${MKDIR} ${PREFIX}/lib/qutim
	@${INSTALL_PROGRAM} ${WRKSRC}/../libicq.so ${PREFIX}/lib/qutim

.include <bsd.port.mk>
