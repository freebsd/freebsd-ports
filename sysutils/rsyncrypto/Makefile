PORTNAME=	rsyncrypto
DISTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	sysutils net
MASTER_SITES=	SF

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Rsync Friendly File Encryption
WWW=		https://rsyncrypto.lingnu.com/ \
		https://sourceforge.net/projects/rsyncrypto/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${GZIP_DEPENDS}
LIB_DEPENDS=	libargtable2.so:devel/argtable
RUN_DEPENDS=	${GZIP_DEPENDS} \
		rsync:net/rsync
TEST_DEPENDS=	${GZIP_DEPENDS} \
		bash:shells/bash

USES=		compiler:c++11-lang gmake localbase shebangfix ssl tar:bzip2

SHEBANG_FILES=	tests/regtest

GNU_CONFIGURE=	yes

TEST_TARGET=	test

# Just to make configure phase runtime checks happy
BINARY_ALIAS=	gzip=${LOCALBASE}/bin/gzip

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

GZIP_DEPENDS=	${LOCALBASE}/bin/gzip:archivers/gzip

# Use gzip from localbase, as gzip from base lacks support of needed --rsyncable option
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/rsyncrypto.h

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
