# New ports collection makefile for:	krdesktop
# Date created:		23 June 2002
# Whom:			Matt Douhan <matt@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	krdesktop
PORTVERSION=	1.1
CATEGORIES=	net kde
MASTER_SITES=	http://krazykiwi.homeip.net/netwizard/krdesktop/
DISTNAME=	${PORTNAME:S/kr/KR/}-${PORTVERSION}

MAINTAINER=	matt@athame.co.uk

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop-devel

USE_KDELIBS_VER=3
NO_WRKSUBDIR=   yes

MAKE_ENV=       QTDIR=${QT_PREFIX} \
		KDEDIR=${LOCALBASE} \
		MOC=${MOC}

CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
