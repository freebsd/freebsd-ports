# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	magicrescue
PORTVERSION=	1.1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.itu.dk/people/jobr/magicrescue/release/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	File recovery tool which recovers deleted files from a block device

LICENSE=	GPLv2

USES=		perl5 shebangfix
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_PERL5=	run

SHEBANG_FILES=	magicsort

OPTIONS_DEFINE=	DOCS

MAKE_ENV+=	STAGEDIR=${STAGEDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/magicrescue
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dupemap
.for f in safecat inputseek textextract
	@${STRIP_CMD} ${STAGEDIR}${DATADIR}/tools/${f}
.endfor

.include <bsd.port.mk>
