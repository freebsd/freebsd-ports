# New ports collection makefile for:   scdp
# Date created:                14 September 2001
# Whom:                        arved@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	scdp
PORTVERSION=	1.0.b
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scdp
DISTNAME=	scdp-${PORTVERSION:S/.b/b/}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"Tool that sends CDP (CISCO Discovery Protocol) Packets"

BUILD_DEPENDS=	libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10

PLIST_FILES=	bin/scdp
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/scdp.c

.include <bsd.port.mk>
