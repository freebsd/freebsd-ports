PORTNAME=	iprange
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/firehol/iprange/releases/download/v${PORTVERSION}/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Manage IP ranges
WWW=		https://github.com/firehol/iprange

LICENSE=	GPLv2+

USES=		tar:xz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/iprange \
		share/man/man1/iprange.1.gz

.include <bsd.port.mk>
