# New ports collection makefile for:	icqnix
# Date created:		27 Aug 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	icqnix
PORTVERSION=	b1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.csie.nctu.edu.tw/~yinjieh/
DISTNAME=	icqnix-beta1

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	ICQ client for the X Window System for UNIX based PCs

RUN_DEPENDS=	esdplay:${PORTSDIR}/audio/esound

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	1
CONFIGURE_ARGS=	--with-qt-libraries=${X11BASE}/lib --with-qt-includes=${X11BASE}/include/X11/qt1
CONFIGURE_ENV=	QT_MOC="${MOC}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501013
BROKEN=		"Configure fails"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/icqnix
	@${STRIP_CMD} ${PREFIX}/bin/icqnix.install

.include <bsd.port.post.mk>
