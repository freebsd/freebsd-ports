# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.18 2004/05/25 22:16:33 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.13.53
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.13/:src \
    		${MASTER_SITE_LOCAL}/gahr/:fonts \
		http://people.freebsd.org/~gahr/distfiles/:fonts \
		http://www.chiark.greenend.org.uk/~sgtatham/gonville/:gonville
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
    		${PORTNAME}-fonts-${PORTVERSION}${EXTRACT_SUFX}:fonts \
		gonville-${GONVILLE_REV}${EXTRACT_SUFX}:gonville
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace \
		rarian-sk-config:${PORTSDIR}/textproc/rarian \
		texi2html:${PORTSDIR}/textproc/texi2html \
		pdftexi2dvi:${PORTSDIR}/print/texinfo \
		zip:${PORTSDIR}/archivers/zip \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
    		gmp.10:${PORTSDIR}/math/gmp
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace

GONVILLE_REV=	r8724
GONVILLE_SIZES=	11 13 14 16 18 20 23 26

#OPTIONS=	WEBDOCS	"Include web documentation" off

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
INSTALLS_OMF=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	all
CONFIGURE_ENV+=	MAKEINFO="${LOCALBASE}/bin/makeinfo"
NOCCACHE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
IGNORE=		installation of webdocs does not work
BUILD_DEPENDS+=	pbmpscale:${PORTSDIR}/graphics/netpbm \
    		rsync:${PORTSDIR}/net/rsync
PLIST_SUB+=	DOCS=""
PORTDOCS+=	*
.else
PLIST_SUB+=	DOCS="@comment "
.endif

post-extract:
	${TAR} -C ${WRKDIR} -xf ${DISTDIR}/${PORTNAME}-fonts-${PORTVERSION}${EXTRACT_SUFX}
	${TAR} -C ${WRKDIR} -xf ${DISTDIR}/gonville-${GONVILLE_REV}${EXTRACT_SUFX} && \
	    ${CP} ${WRKDIR}/gonville-${GONVILLE_REV}/lilyfonts/otf/* ${WRKSRC}/mf/out/
.for size in ${GONVILLE_SIZES}
	${LN} -s ${WRKSRC}/mf/out/gonville${size}.otf ${WRKSRC}/mf/out/gonville-${size}.otf
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|makeinfo|${LOCALBASE}/bin/makeinfo|' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|<FlexLexer.h>|"/usr/include/FlexLexer.h"|' \
	    ${WRKSRC}/lily/include/includable-lexer.hh
	${REINPLACE_CMD} -e 's|sed|gsed|g' ${WRKSRC}/Documentation/GNUmakefile
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '17,21d' ${WRKSRC}/po/GNUmakefile
.endif

pre-install:
.if exists(${PREFIX}/info/dir)
	${REINPLACE_CMD} -i '' -e '/LilyPond/d' ${PREFIX}/info/dir
.endif

post-install:
	@${LN} -s ${DATADIR}/${PORTVERSION} ${DATADIR}/current
.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
	@echo "Installing documentation... this takes a while..."
	cd ${WRKSRC} && ${GMAKE} doc install-doc
#	@(cd ${WRKSRC}/out-www/offline-root && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
