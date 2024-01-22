PORTNAME=	heirloom-doctools
PORTVERSION=	191015
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities
WWW=		https://n-t-roff.github.io/heirloom/doctools.html

LICENSE=	CDDL

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	n-t-roff

ALL_TARGET=	#empty
MAKE_ARGS+=	INSTALL="${INSTALL}" \
		BINDIR=${BINDIR} \
		LIBDIR=${LIBDIR} \
		PUBDIR=${PUBDIR} \
		MANDIR=${MANDIR} \
		MACDIR=${MACDIR} \
		FNTDIR=${FNTDIR} \
		PSTDIR=${PSTDIR} \
		TABDIR=${TABDIR} \
		HYPDIR=${HYPDIR} \
		REFDIR=${REFDIR} \
		ROOT=${STAGEDIR}
MAKEFILE=	makefile
CFLAGS+=	-fcommon
SUB_FILES=	${PORTNAME}.conf
PLIST_SUB=	LIBEXECDIR=heirloom/libexec

MANDIRS=	${PREFIX}/heirloom/share/man
DATADIR=	${PREFIX}/heirloom/share

MACDIR?=	${DATADIR}/tmac
FNTDIR?=	${DATADIR}/font
TABDIR?=	${DATADIR}/nterm
HYPDIR?=	${DATADIR}/hyphen
REFDIR?=	${PREFIX}/heirloom/libexec/reftools
PUBDIR?=	${DATADIR}/pub
BINDIR?=	${PREFIX}/heirloom/bin
LIBDIR?=	${PREFIX}/heirloom/libexec
PSTDIR?=	${DATADIR}/font/devpost/postscript
MANDIR?=	${PREFIX}/heirloom/share/man

PORTDOCS=	 *

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/man.d

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
