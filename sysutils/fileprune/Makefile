PORTNAME=	fileprune
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	dds@FreeBSD.org
COMMENT=	Prune a file set according to a given age distribution
WWW=		https://www.spinellis.gr/sw/unix/fileprune/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	dspinellis
GH_TAGNAME=	2dd22fc

PLIST_FILES=	bin/fileprune share/man/man1/fileprune.1.gz
MAKE_ARGS=	CFLAGS="${CFLAGS}" PREFIX="${STAGEDIR}${PREFIX}"

.include <bsd.port.mk>
