# New ports collection makefile for:	krdesktop
# Date created:		23 June 2002
# Whom:			Matt Douhan <matt@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	krdesktop
PORTVERSION=	1.0
CATEGORIES=	net kde
MASTER_SITES=	http://krazykiwi.homeip.net/netwizard/krdesktop/
DISTNAME=	${PORTNAME:S/kr/KR/}-${PORTVERSION}

MAINTAINER=	matt@athame.co.uk

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop-devel

USE_KDELIBS_VER=3
USE_REINPLACE=	yes
NO_WRKSUBDIR=   yes
REINPLACE_ARGS=	-E -i.bak

MAKE_ENV=       QTDIR=${QT_PREFIX} \
		KDEDIR=${LOCALBASE} \
		MOC=${MOC}

CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,^(CXX|MOC|CXXFLAGS)\+?=,\1?=,g' \
		-e 's,(\$$\(CXX\) )(\$$\(CXXFLAGS),\1-c \2,g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
