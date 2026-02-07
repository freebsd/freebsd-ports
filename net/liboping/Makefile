PORTNAME=	liboping
DISTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://noping.cc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Liboping, a C library, and utility to generate ICMP echo requests
WWW=		https://noping.cc/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool ncurses perl5 shebangfix
CPE_VENDOR=	noping
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
	--mandir=${PREFIX}/share/man

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Oping/Oping.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liboping.so.0.3.0

.include <bsd.port.mk>
