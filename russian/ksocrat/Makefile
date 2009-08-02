# New ports collection makefile for:   	ksocrat
# Date created:        	30.04.2003
# Whom:                	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	ksocrat
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	russian kde
MASTER_SITES=	http://ksocrat.linux.kiev.ua/download/

MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-enru-dic-1.0.1${EXTRACT_SUFX} \
		${PORTNAME}-ruen-dic-1.0.1${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KSocrat is the simple English/Russian Russian/English dictionary

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

RESTRICTED=	"Redistribution not allowed"
NO_CDROM=	${RESTRICTED}

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-install:
		${INSTALL_DATA} ${WRKDIR}/usr/share/apps/ksocrat/* \
			 ${PREFIX}/share/apps/ksocrat

.include <bsd.port.mk>
