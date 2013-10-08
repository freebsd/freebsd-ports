# Created by: webmaster@kibab.com
# $FreeBSD$

PORTNAME=	qutim
PORTVERSION=	0.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
DISTNAME=	qutim_${PORTVERSION}_svn529

MAINTAINER=	webmaster@kibab.com
COMMENT=	Qt4-based multiprotocol IM client with advanced features

DEPRECATED=	Old version, a new one needs to be ported from scratch
EXPIRATION_DATE=	2013-11-05

USE_QT4=	designer_build	\
		gui		\
		imageformats	\
		moc_build	\
		network		\
		qmake_build	\
		rcc_build	\
		script_build	\
		uic_build	\
		webkit		\
		xml
USE_XORG=	xscrnsaver


USES=		cmake
CMAKE_ARGS+=	-DUNIX:BOOL=1 -DBSD:BOOL=1
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
