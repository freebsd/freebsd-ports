PORTNAME=	utftools
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.cs.yorku.ca/pub/wily/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-aware wc, fmt, expand, and unexpand
WWW=		http://www.cs.yorku.ca/~oz/

LICENSE=	UTFTOOLS
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_NAME=	utftools license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libutf.a:misc/libutf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|man$$|share/man|' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
