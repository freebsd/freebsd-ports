PORTNAME=	pax-utils
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Various ELF related utils for ELF32, ELF64 binaries
WWW=		https://www.gentoo.org/proj/en/hardened/pax-utils.xml

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
		share/man/man1/dumpelf.1.gz \
		share/man/man1/pspax.1.gz \
		share/man/man1/scanelf.1.gz \
		share/man/man1/scanmacho.1.gz
PORTDOCS=	BUGS COPYING README.md TODO

OPTIONS_DEFINE=	DOCS

pre-install:
	@(cd ${WRKSRC}/man; ${GMAKE} man)

do-install:
.for f in dumpelf pspax scanelf scanmacho
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${f}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
