PORTNAME=	tthsum
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://tthsum.devs.nu/pkg/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility for generating and checking TTH message digests
WWW=		http://tthsum.devs.nu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

CONFLICTS=	microdc2

USES=		gmake

PLIST_FILES=	bin/tthsum share/man/man1/tthsum.1.gz

WRKSRC=		${WRKDIR}/${PORTNAME}
TEST_TARGET=	runtest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
