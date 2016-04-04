# $FreeBSD$

PORTNAME=	heirloom-doctools
PORTVERSION=	0.0.160217
DISTVERSION=	${PORTVERSION:S,0.0.,,}
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

LICENSE=	CDDL

CONFLICTS=	libotf-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	n-t-roff

USES=	gmake
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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
