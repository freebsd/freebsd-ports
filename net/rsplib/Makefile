# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	rsplib
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.exp-math.uni-essen.de/~dreibh/rserpool/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode \
		--enable-qt --with-qt-lib=${QT_LIBDIR} \
		--with-qt-include=${QT_INCDIR}
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_LDCONFIG=	yes
USE_QT4=	gui xml moc_build

.include <bsd.port.mk>
