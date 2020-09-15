# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	hashcash
PORTVERSION=	1.22
CATEGORIES=	mail
MASTER_SITES=	http://www.hashcash.org/source/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Anti-spam / denial of service counter-measure tool

LICENSE=	CPL
LICENSE_NAME=	CPL
LICENSE_TEXT=	http://www.cypherspace.org/CPL/
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:tgz

PLIST_FILES=	bin/hashcash bin/sha1
PLIST_FILES+=	man/man1/hashcash.1.gz
PLIST_FILES+=	man/man1/sha1-hashcash.1.gz

PORTDOCS=	CHANGELOG LICENSE README
ALL_TARGET=	generic

MAKE_ENV+=	STAGEDIR=${STAGEDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
USE_GCC=	any
.endif

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/DOC_INSTALL_PATH/d' ${WRKSRC}/Makefile

.include <bsd.port.mk>
