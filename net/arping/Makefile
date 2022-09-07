PORTNAME=	arping
DISTVERSION=	2.21
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	ARP level "ping" utility
WWW=		https://www.habets.pp.se/synscan/programs.php?prog=arping

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnet.so:net/libnet

USES=		localbase
USE_CSTD=	c99
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/arping man/man8/arping.8.gz

.include <bsd.port.mk>
