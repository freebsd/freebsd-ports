# New ports collection makefile for:   	ksocrat
# Date created:        	30.04.2003
# Whom:                	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	ksocrat
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	russian kde
MASTER_SITES=	http://ksocrat.linux.kiev.ua/download/ \
		http://voodoo.oberon.net/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-enru-dic-1.0.1${EXTRACT_SUFX} \
		${PORTNAME}-ruen-dic-1.0.1${EXTRACT_SUFX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	KSocrat is the simple English/Russian Russian/English dictionary

USE_SIZE=	yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

RESTRICTED=	"Redistribution not allowed"
NO_CDROM=	${RESTRICTED}
#NO_PACKAGE=	${RESTRICTED}

ONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-install:
		${INSTALL_DATA} ${WRKDIR}/usr/share/apps/ksocrat/* \
			 ${PREFIX}/share/apps/ksocrat

.include <bsd.port.mk>
