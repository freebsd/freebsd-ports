# New ports collection makefile for:	icqnix
# Date created:		27 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	icqnix
PORTVERSION=	b1
CATEGORIES=	net
MASTER_SITES=	http://www.csie.nctu.edu.tw/~yinjieh/
DISTNAME=	icqnix-beta1

MAINTAINER=	yinjieh@csie.nctu.edu.tw

RUN_DEPENDS=	esdplay:${PORTSDIR}/audio/esound

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	1
CONFIGURE_ARGS=	--with-qt-libraries=${X11BASE}/lib --with-qt-includes=${X11BASE}/include/X11/qt1
CONFIGURE_ENV=	QT_MOC="${MOC}"

post-install:
	@strip ${PREFIX}/bin/icqnix
	@strip ${PREFIX}/bin/icqnix.install

.include <bsd.port.mk>
