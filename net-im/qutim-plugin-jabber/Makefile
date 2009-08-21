# New ports collection makefile for:	qutim-plugin-jabber
# Date created:		Sun Aug  2 23:37:39 MSD 2009
# Whom:			webmaster@kibab.com
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	0.2b
CATEGORIES=	net-im
MASTER_SITES=	http://qutim.org/download/ \
		http://dl.kibab.com/distfiles/qutim/ \
		ftp://ftp.inferra.ru/pub/qutim/
PKGNAMEPREFIX=	qutim-plugin-
DISTNAME=	qutim-jabber_${PORTVERSION}_svn366

MAINTAINER=	webmaster@kibab.com
COMMENT=	Jabber protocol plugin for qutIM

BUILD_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim
RUN_DEPENDS=	${LOCALBASE}/bin/qutim:${PORTSDIR}/net-im/qutim

USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build

CXXFLAGS+=	-L${LOCALBASE}/lib

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

WRKSRC=		${WRKDIR}/jabber

OPTIONS=	GNUTLS "Use GNUTLS (required for GMail)" on

.include <bsd.port.options.mk>

.if defined(WITH_GNUTLS)
CMAKE_ARGS+=	-DGNUTLS=1
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/qutim
	@${INSTALL_PROGRAM} ${WRKSRC}/libjabber.so ${PREFIX}/lib/qutim

.include <bsd.port.mk>
