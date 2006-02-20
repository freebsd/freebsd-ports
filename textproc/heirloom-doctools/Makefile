# Ports collection makefile for:  heirloom-doctools
# Date created:			  Saturday, 3 December 2005
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	heirloom-doctools
PORTVERSION=	0.0.060208
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	heirloom/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Portable and enhanced troff, nroff, and related utilities

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	#empty
MAKE_ENV+=	INSTALL=${INSTALL} \
		MACDIR=${MACDIR} \
		FNTDIR=${FNTDIR} \
		TABDIR=${TABDIR} \
		HYPDIR=${HYPDIR} \
		REFDIR=${REFDIR} \
		PUBDIR=${PUBDIR} \
		BINDIR=${BINDIR} \
		LIBDIR=${LIBDIR} \
		MANDIR=${MANDIR}
MAKEFILE=	makefile

MACDIR?=	${PREFIX}/share/doctools/tmac
FNTDIR?=	${PREFIX}/share/doctools/font
TABDIR?=	${PREFIX}/share/doctools/nterm
HYPDIR?=	${PREFIX}/share/doctools/hyphen
REFDIR?=	${PREFIX}/libexec/doctools/reftools
PUBDIR?=	${PREFIX}/share/doctools/pub
BINDIR?=	${PREFIX}/bin
LIBDIR?=	${PREFIX}/libexec/doctools
MANDIR?=	${PREFIX}/man

MAN1+=		vgrind.1 troff.1 tbl.1 sortbib.1 \
		soelim.1 roffbib.1 refer.1 ptx.1 \
		picpack.1 pic.1 otfdump.1 nroff.1 \
		neqn.1 lookbib.1 grap.1 \
		eqn.1 checknr.1 addbib.1
MAN7+=		eqnchar.7 mpictures.7 mcolor.7
MLINKS+=	lookbib.1 indxbib.1 \
		eqn.1 checkeq.1

DOCS=		CHANGES FONTS NEWS PDFS README \
		LICENSE/BERKELEY.LICENSE \
		LICENSE/CALDERA.LICENSE \
		LICENSE/COPYING.LGPL \
		LICENSE/LPPL-1-0.LICENSE \
		LICENSE/LUCENT.LICENSE \
		LICENSE/OPENSOLARIS.LICENSE

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Does not compile on FreeBSD 4.x
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
