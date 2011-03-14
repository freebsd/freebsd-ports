# New ports collection makefile for:	qutim-plugin-jabber
# Date created:		Sun Aug  2 23:37:39 MSD 2009
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	0.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/download/ \
		http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
PKGNAMEPREFIX=	qutim-plugin-
DISTNAME=	qutim-jabber_${PORTVERSION}_svn431

MAINTAINER=	webmaster@kibab.com
COMMENT=	Jabber protocol plugin for qutIM

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn
BUILD_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim
RUN_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim

USE_QT_VER=	4
QT_COMPONENTS=	gui		\
		moc_build	\
		network		\
		qmake_build	\
		rcc_build	\
		uic_build	\
		xml

CXXFLAGS+=	-L${LOCALBASE}/lib

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

WRKSRC=		${WRKDIR}/jabber

OPTIONS=	GNUTLS "Use GNUTLS (required for GMail)" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GNUTLS)
CMAKE_ARGS+=	-DGNUTLS=1
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/qutim
	@${INSTALL_PROGRAM} ${WRKSRC}/libjabber.so ${PREFIX}/lib/qutim

.include <bsd.port.mk>
