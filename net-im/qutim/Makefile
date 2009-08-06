# New ports collection makefile for:	qutim
# Date created:		Mon Jun 16 20:42:11 MSD 2008
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	qutim
PORTVERSION=	0.1.1
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/download/ \
		http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutIM/
DISTNAME=	qutim_${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	A Qt4-based lightweight ICQ client with advanced features

BROKEN=		doesn't build with new QT 4.5

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/qutIM

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o Makefile qutIM.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/build/bin/qutIM ${PREFIX}/bin

.include <bsd.port.mk>
