# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.18 2004/05/25 22:16:33 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.13.3
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.13/:src \
    		${MASTER_SITE_LOCAL}/gahr/:fonts \
		http://people.freebsd.org/~gahr/distfiles/:fonts
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
    		${PORTNAME}-fonts-${PORTVERSION}${EXTRACT_SUFX}:fonts
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace \
		rarian-sk-config:${PORTSDIR}/textproc/rarian \
		texi2html:${PORTSDIR}/textproc/texi2html \
		pdftexi2dvi:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
    		gmp.8:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace

OPTIONS=	WEBDOCS	"Build and install documentation" off

MAN1=		lilymidi.1 lilypond-book.1 lilypond-invoke-editor.1 \
		lilypond.1 lilysong.1 convert-ly.1 abc2ly.1 etf2ly.1 \
		midi2ly.1 musicxml2ly.1
INFO=		lilypond lilypond-internals lilypond-program lilypond-learning \
		music-glossary

USE_AUTOTOOLS=	autoconf:262
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	pango
INSTALLS_OMF=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	all
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" MAKEINFO="${LOCALBASE}/bin/makeinfo"
NOCCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
BUILD_DEPENDS+=	pbmpscale:${PORTSDIR}/graphics/netpbm
ALL_TARGET+=	doc
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

post-extract:
	${TAR} -C ${WRKDIR} -xf ${DISTDIR}/${PORTNAME}-fonts-${PORTVERSION}${EXTRACT_SUFX}

post-patch:
	${REINPLACE_CMD} -e 's|makeinfo|${LOCALBASE}/bin/makeinfo|' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
#	Documentation in Spanish does not build...
	${REINPLACE_CMD} -e '70s|es, ||' ${WRKSRC}/python/langdefs.py
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '17,21d' ${WRKSRC}/po/GNUmakefile
.endif

post-install:
	@${LN} -s ${DATADIR}/${PORTVERSION} ${DATADIR}/current
.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
	@echo "Installing documentation... this takes a while..."
	@(cd ${WRKSRC}/out-www/offline-root && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
