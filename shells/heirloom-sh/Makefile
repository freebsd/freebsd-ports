PORTNAME=	heirloom-sh
PORTVERSION=	050706
PORTREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	SF/heirloom/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable version of OpenSolaris' Bourne Shell
WWW=		https://heirloom.sourceforge.net/sh.html

LICENSE=	CDDL

BROKEN_aarch64=	fails to link: missing sbrk
BROKEN_riscv64=	fails to link: missing sbrk

USES=		tar:bzip2

MAKEFILE=	makefile
MAKE_ARGS=	ROOT=${STAGEDIR} \
		SV3BIN=${PREFIX}/heirloom/bin \
		MANDIR=${PREFIX}/heirloom/share/man \
		UCBINST=${INSTALL}
SUB_FILES=	${PORTNAME}.conf
PLIST_FILES=	"@shell heirloom/bin/sh" \
		"@shell heirloom/bin/jsh" \
		etc/man.d/${PORTNAME}.conf \
		heirloom/share/man/man1/sh.1.gz \
		heirloom/share/man/man1/jsh.1.gz
PORTDOCS=	CALDERA.LICENSE OPENSOLARIS.LICENSE CHANGES README

OPTIONS_DEFINE=	DOCS

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/man.d

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
