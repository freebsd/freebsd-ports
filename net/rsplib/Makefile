# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	rsplib
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.exp-math.uni-essen.de/~dreibh/rserpool/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

LICENSE=	GPLv3

BROKEN=		fails to compile: fractalgeneratorservice.cc:353:12: expected unqualified-id

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode \
		--enable-qt --with-qt-lib=${QT_LIBDIR} \
		--with-qt-include=${QT_INCDIR}
INSTALL_TARGET=	install-strip
USES=		gmake libtool qt:4 shebangfix
SHEBANG_FILES=	rsplib/scriptingserviceexample
USE_LDCONFIG=	yes
USE_QT=		gui xml moc_build

.include <bsd.port.mk>
