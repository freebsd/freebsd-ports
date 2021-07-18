# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	shuf
DISTVERSION=	3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ibara/shuf/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Randomly permute input lines

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/shuf \
		share/man/man1/shuf.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shuf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shuf.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
