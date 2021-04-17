# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	shuf
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.0
CATEGORIES=	sysutils

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Randomly permute input lines

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ibara
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/shuf \
		share/man/man1/shuf.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shuf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shuf.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
