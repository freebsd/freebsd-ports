PORTNAME=	xe
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple xargs and apply replacement
WWW=		https://github.com/leahneukirchen/xe/

LICENSE=	CC0-1.0

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen
USE_PERL5=	test

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"
TEST_TARGET=	check

PLIST_FILES=	bin/xe \
		share/man/man1/xe.1.gz \
		share/zsh/site-functions/_xe

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xe

.include <bsd.port.mk>
