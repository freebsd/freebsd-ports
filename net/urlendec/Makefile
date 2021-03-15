# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	urlendec
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	URL encoder and decoder written in assembly

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	written in x86 assembly language

BUILD_DEPENDS=	nasm:devel/nasm

PLIST_FILES=	bin/urlencode bin/urldecode
PORTDOCS=	index.html rfc1738.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^[[:blank:]]*ld/s,-o,-m elf_i386_fbsd &, \
		; /^[[:blank:]]*nasm/s,elf,&32,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^section/s,code,text,' ${WRKSRC}/*.asm

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:[1..2]:T:S,^,${WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
