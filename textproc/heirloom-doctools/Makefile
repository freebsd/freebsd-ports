# $FreeBSD$

PORTNAME=	heirloom-doctools
PORTVERSION=	160308
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

LICENSE=	CDDL

BROKEN_powerpc64=	fails to package: Unable to access file pub/utf-8: No such file or directory

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
PLIST_SUB=	LIBEXECDIR=libexec/${PORTNAME}

MACDIR?=	${DATADIR}/tmac
FNTDIR?=	${DATADIR}/font
TABDIR?=	${DATADIR}/nterm
HYPDIR?=	${DATADIR}/hyphen
REFDIR?=	${PREFIX}/libexec/${PORTNAME}/reftools
PUBDIR?=	${DATADIR}/pub
BINDIR?=	${PREFIX}/bin
LIBDIR?=	${PREFIX}/libexec/${PORTNAME}
PSTDIR?=	${DATADIR}/font/devpost/postscript
MANDIR?=	${PREFIX}/man

PORTDOCS=	 *

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
