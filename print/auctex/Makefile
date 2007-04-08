# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		11.84
PORTREVISION=		0
CATEGORIES=		print elisp
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Integrated environment for writing LaTeX using GNU Emacs

BUILD_DEPENDS=	${MKTEXLSR}:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${MKTEXLSR}:${PORTSDIR}/print/teTeX-base

USE_GHOSTSCRIPT=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${LISPDIR} \
		--with-auto-dir=${PREFIX}/${LISPDIR}/auctex/auto \
		--with-texmf-dir=${PREFIX}/${TEXMFDIR} \
		--infodir=${PREFIX}/info

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}

PLIST_SUB+=	LISPDIR=${LISPDIR} \
		TEXMFDIR=${TEXMFDIR} \
		MKTEXLSR=${MKTEXLSR}
INFO=		auctex preview-latex

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

NOT_FOR_ARCHS=	ia64

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
