# New ports collection makefile for:   	ksocrat
# Date created:        	30.04.2003
# Whom:                	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	ksocrat
PORTVERSION=	3.2.1
PORTREVISION=	7
CATEGORIES=	russian kde
MASTER_SITES=	http://ksocrat.linux.kiev.ua/download/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-enru-dic-1.0.1${EXTRACT_SUFX} \
		${PORTNAME}-ruen-dic-1.0.1${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KSocrat is the simple English/Russian Russian/English dictionary

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

RESTRICTED=	Redistribution not allowed

LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
		${INSTALL_DATA} ${WRKDIR}/usr/share/apps/ksocrat/* \
			 ${PREFIX}/share/apps/ksocrat

.include <bsd.port.mk>
