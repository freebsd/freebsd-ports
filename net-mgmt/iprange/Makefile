PORTNAME=	iprange
PORTVERSION=	2.0.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/firehol/iprange/releases/download/v${PORTVERSION}/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Manage IP ranges
WWW=		https://github.com/firehol/iprange

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

IGNORE_i386=	__uint128_t is not available on i386 and is required for mandatory IPv6 support

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/iprange \
		share/man/man1/iprange.1.gz

.include <bsd.port.mk>
