# New ports collection makefile for:	lilypond
# Date created:				2001-02-10
# Whom:					trevor
# based on NetBSD pkgsrc/print/lilypond
#
# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:32:11 rh Exp $
# $FreeBSD$
#

PORTNAME=	lilypond
PORTVERSION=	1.3.131
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/development/

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	YES
#CONFIGURE_ENV=	${MAKEINFO}="makeinfo --no-split"

MAN1=	abc2ly.1 as2text.1 convert-ly.1 etf2ly.1 lilypond-book.1 \
	lilypond.1 ly2dvi.1 midi2ly.1 musedata2ly.1 pmx2ly.1

USE_GMAKE=	YES
USE_PYTHON=	YES
MAKEFILE=	GNUmakefile

INFO_FILES=	lilypond.info lilypond-internals.info

post-configure:
	${PERL} -pi -e "s:^INFO_FILES:xxxINFO_FILES:g" \
		${WRKSRC}/Documentation/user/GNUmakefile
#	${PERL} -pi -e "s:force:force --no-split:g" \
#		${WRKSRC}/Documentation/user/GNUmakefile

post-install:
.for i in make stepmake config.make tfm.3 tfm.4 tfm.5
	${RM} -rf ${PREFIX}/share/lilypond/${i}
.endfor
#.for i in ${INFO_FILES}
#	install-info ${PREFIX}/info/${i} ${PREFIX}/info/dir
#.endfor

CONFIGURE_ARGS+=--disable-kpathsea

.include <bsd.port.mk>
