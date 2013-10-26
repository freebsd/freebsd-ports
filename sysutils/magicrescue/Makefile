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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
