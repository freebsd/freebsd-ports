PORTNAME=	bc
DISTVERSION=	1.07.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU bc/dc calculator
WWW=		https://www.gnu.org/software/bc/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to build: tests fail with error code 2

USES=		cpe libedit makeinfo
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libedit
INFO=		bc \
		dc
PLIST_FILES=	bin/bc \
		bin/dc \
		share/man/man1/bc.1.gz \
		share/man/man1/dc.1.gz
PORTEXAMPLES=	ckbook.b \
		pi.b \
		primes.b \
		twins.b

OPTIONS_DEFINE=	EXAMPLES

CONFLICTS_INSTALL=	gh-bc

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
