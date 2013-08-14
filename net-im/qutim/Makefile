# New ports collection makefile for:	qutim
# Date created:		Mon Jun 16 20:42:11 MSD 2008
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	qutim
PORTVERSION=	0.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
DISTNAME=	qutim_${PORTVERSION}_svn529

MAINTAINER=	webmaster@kibab.com
COMMENT=	A Qt4-based multiprotocol IM client with advanced features

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

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
