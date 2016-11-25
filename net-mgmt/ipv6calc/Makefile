# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	ipv6calc
PORTVERSION=	0.96.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	ftp://ftp.bieringer.de/pub/linux/IPv6/ipv6calc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert, change, and calculate with IPv6 addresses

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake perl5 ssl
GNU_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
