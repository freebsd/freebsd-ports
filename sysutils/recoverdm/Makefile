PORTNAME=	recoverdm
PORTVERSION=	0.20
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recover files and discs with damaged sectors

LICENSE=	AGPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	flok99
GH_TAGNAME=	8ecb743

PLIST_FILES=	bin/mergebad bin/recoverdm man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
