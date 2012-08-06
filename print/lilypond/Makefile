# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.18 2004/05/25 22:16:33 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.14.2
PORTREVISION=	2
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.14/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace \
		rarian-sk-config:${PORTSDIR}/textproc/rarian \
		texi2html:${PORTSDIR}/textproc/texi2html \
		pdftexi2dvi:${PORTSDIR}/print/texinfo \
		zip:${PORTSDIR}/archivers/zip \
		gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/share/ghostscript/fonts/c059033l.pfb:${PORTSDIR}/print/gsfonts
LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile \
    		gmp.10:${PORTSDIR}/math/gmp
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans-Bold.ttf:${PORTSDIR}/x11-fonts/dejavu

MAN1=		lilymidi.1 lilypond-book.1 lilypond-invoke-editor.1 \
		lilypond.1 lilysong.1 convert-ly.1 abc2ly.1 etf2ly.1 \
		midi2ly.1 musicxml2ly.1
INFO=		lilypond-changes lilypond-contributor lilypond-essay \
		lilypond-extending lilypond-internals lilypond-learning \
		lilypond-notation lilypond-usage lilypond-web \
		music-glossary

USE_AUTOTOOLS=	autoconf
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	pango
MAKEFILE=	GNUmakefile
GNU_MAKEFILE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS+=--with-ncsb-dir=${LOCALBASE}/share/ghostscript/fonts
CONFIGURE_ENV+=	MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} \
		YACC=${YACC}

ALL_TARGET=	all

NOCCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|makeinfo|${LOCALBASE}/bin/makeinfo|; s|find -maxdepth|find . -maxdepth|g' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '17,21d' ${WRKSRC}/po/GNUmakefile
.endif

pre-su-install:
.if exists(${PREFIX}/info/dir)
	${REINPLACE_CMD} -i '' -e '/LilyPond/d' ${PREFIX}/info/dir
.endif

post-install:
	@${LN} -s ${DATADIR}/${PORTVERSION} ${DATADIR}/current

.include <bsd.port.post.mk>
