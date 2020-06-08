# Created by: kaz
# $FreeBSD$

PORTNAME=	vrfy
PORTVERSION=	1.0
DISTVERSIONPREFIX=v
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Verify mail address

USE_GITHUB=	yes
GH_ACCOUNT=	asxe

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" RES=""
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vrfy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
