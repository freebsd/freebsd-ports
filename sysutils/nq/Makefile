PORTNAME=	nq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Unix command line queue utility
WWW=		https://github.com/leahneukirchen/nq

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen # Think thrice before switching to some random fork
USE_PERL5=	test

MAKE_ARGS=	CFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nq
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nqtail
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/_nq ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_nq

.include <bsd.port.mk>
