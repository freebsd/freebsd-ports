PORTNAME=	hf
PORTVERSION=	1.9
CATEGORIES=	sysutils
MASTER_SITES=	https://ee.lbl.gov/downloads/hf/ \
		LOCAL/leres/hf
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Address to hostname filter

LICENSE=	BSD3CLAUSE

CONFLICTS=	hf

PLIST_FILES=	bin/hf \
		man/man1/hf.1.gz

GNU_CONFIGURE=	yes

# Only install hf
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hf.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
