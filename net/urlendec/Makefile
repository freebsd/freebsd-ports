# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	urlendec
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	URL encoder and decoder

BUILD_DEPENDS=	nasm:devel/nasm

ONLY_FOR_ARCHS=	i386

BINARIES=	urlencode urldecode
DOCFILES=	index.html rfc1738.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BINARIES:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/urlendec
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/share/doc/urlendec

.include <bsd.port.mk>
