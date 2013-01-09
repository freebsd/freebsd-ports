# Created by: Timothy Redaelli
# $FreeBSD$

PORTNAME=	pax-utils
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://dev.gentoo.org/~vapier/dist/ \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

LICENSE=	GPLv2

USE_XZ=		true
USE_GMAKE=	true

PLIST_FILES=	bin/dumpelf bin/pspax bin/scanelf bin/scanmacho

MAN1=		dumpelf.1 pspax.1 scanelf.1 scanmacho.1

OPTIONS_DEFINE=	DOCS

PORTDOCS=	BUGS README TODO

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800076
BROKEN=	Does not build
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.for f in ${MAN1:S,.1,,}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/,} ${PREFIX}/man/man1

.include <bsd.port.mk>
