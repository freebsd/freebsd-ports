PORTNAME=	bitwarden
DISTVERSIONPREFIX=	v
DISTVERSION=	1.22.1
CATEGORIES=	security linux
MASTER_SITES=	https://github.com/bitwarden/cli/releases/download/${DISTVERSIONFULL}/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-cli
DISTNAME=	bw-linux-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Bitwarden CLI

LICENSE=	GPLv3

USES=		linux zip

# install(1) fails with the following messages when stripping:
# strip: elf_update() failed: Layout constraint violation
# strip: elf_update() failed: Layout constraint violation
STRIP=

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/bw

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bw

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bw ${STAGEDIR}${PREFIX}/bin/

do-test:
	${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/bw help >/dev/null

.include <bsd.port.mk>
