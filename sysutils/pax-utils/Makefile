# Created by: Timothy Redaelli
# $FreeBSD$

PORTNAME=	pax-utils
PORTVERSION=	0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://dev.gentoo.org/~vapier/dist/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

LICENSE=	GPLv2

USES=		gmake tar:xz

PLIST_FILES=	bin/dumpelf bin/pspax bin/scanelf bin/scanmacho \
		man/man1/dumpelf.1.gz man/man1/pspax.1.gz \
		man/man1/scanelf.1.gz man/man1/scanmacho.1.gz
PORTDOCS=	BUGS README TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.for f in dumpelf pspax scanelf scanmacho
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${f}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
