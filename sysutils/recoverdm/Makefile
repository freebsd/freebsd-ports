PORTNAME=	recoverdm
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recover files and discs with damaged sectors
WWW=		http://www.vanheusden.com/recoverdm/

LICENSE=	AGPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	flok99
GH_TAGNAME=	8ecb743

PLIST_FILES=	bin/mergebad bin/recoverdm share/man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
