PORTNAME=	webresolve
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://siag.nu/pub/webresolve/ \
		ftp://siag.nu/pub/webresolve/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Webresolve resolves IP addresses to host names in web log files
WWW=		https://siag.nu/webresolve/

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
ALL_TARGET=	webresolve

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; s|\-g||' \
		-e 's|$$(PREFIX)/man|$$(PREFIX)/share/man|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
