# New ports collection makefile for:	urlendec
# Date created:				25 October 2000
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	urlendec
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	URL encoder and decoder

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

BINARIES=	urlencode urldecode
DOCFILES=	index.html rfc1738.txt

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/urlendec
.for f in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/share/doc/urlendec
.endfor
	@echo ""
	@echo "	----------------------------------------------------"
	@echo "	Please read ${PREFIX}/share/doc/urlendec/index.html"
	@echo "	for detailed instructions how to use this port."
	@echo "	----------------------------------------------------"
	@echo ""
.endif

.include <bsd.port.mk>
