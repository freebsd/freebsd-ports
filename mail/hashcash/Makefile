# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	hashcash
PORTVERSION=	1.22
CATEGORIES=	mail
MASTER_SITES=	http://www.hashcash.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Anti-spam / denial of service counter-measure tool

LICENSE=BSD LGPL21 GPLv2
LICENSE_COMB=dual

# Also CPL: https://en.wikipedia.org/wiki/Common_Public_License
# and Public Domain

MAN1=		hashcash.1 sha1-hashcash.1
PLIST_FILES=	bin/hashcash bin/sha1
PLIST_FILES+= man/man1/hashcash.1.gz
PLIST_FILES+= man/man1/sha1-hashcash.1.gz

PORTDOCS=	CHANGELOG LICENSE README
ALL_TARGET=	generic

MAKE_ENV+= STAGEDIR=${STAGEDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}

post-patch:
	${REINPLACE_CMD} -e '/DOC_INSTALL_PATH/d' ${WRKSRC}/Makefile

.endif

.include <bsd.port.mk>
