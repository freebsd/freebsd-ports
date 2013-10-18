# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mooseekd
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://files.backtrace.info/releases/mooseekd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A daemon to connect to the Soulseek network

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26

BROKEN=		checksum mismatch

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
USE_FAM=	yes
USES=		iconv

NO_STAGE=	yes
.include <bsd.port.mk>
