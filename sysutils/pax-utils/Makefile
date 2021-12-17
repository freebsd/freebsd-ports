# Created by: Timothy Redaelli

PORTNAME=	pax-utils
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	gentoo

PLIST_FILES=	bin/dumpelf \
		bin/pspax \
		bin/scanelf \
		bin/scanmacho \
		man/man1/dumpelf.1.gz \
		man/man1/pspax.1.gz \
		man/man1/scanelf.1.gz \
		man/man1/scanmacho.1.gz
PORTDOCS=	BUGS COPYING README.md TODO

OPTIONS_DEFINE=	DOCS

pre-install:
	@(cd ${WRKSRC}/man; ${GMAKE} man)

do-install:
.for f in dumpelf pspax scanelf scanmacho
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${f}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
