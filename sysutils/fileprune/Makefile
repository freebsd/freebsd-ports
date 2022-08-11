PORTNAME=	fileprune
PORTVERSION=	1.12
CATEGORIES=	sysutils

MAINTAINER=	dds@FreeBSD.org
COMMENT=	Prune a file set according to a given age distribution

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	dspinellis
GH_TAGNAME=	2dd22fc

PLIST_FILES=	bin/fileprune man/man1/fileprune.1.gz
MAKE_ARGS=	CFLAGS="${CFLAGS}" PREFIX="${STAGEDIR}${PREFIX}"

post-extract:
	${REINPLACE_CMD} -e 's,/share,,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
