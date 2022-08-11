PORTNAME=	asm-xml
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://tibleiz.net/download/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Very fast XML parser and decoder written in pure assembler

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	fasm:lang/fasm

USES=		dos2unix uidfix

PLIST_FILES=	include/asm-xml.h lib/libasm-xml.a

post-extract:
	${RM} -r ${WRKSRC}/obj

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
