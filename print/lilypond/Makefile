# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.18 2004/05/25 22:16:33 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.11.51
CATEGORIES=	print audio
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.11/:src \
    		http://download.linuxaudio.org/lilypond/binaries/freebsd-x86/:bin
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
    		${PORTNAME}-${PORTVERSION}-1.freebsd-x86.sh:bin
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace \
		rarian-sk-config:${PORTSDIR}/textproc/rarian \
		texi2pdf:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	guile.18:${PORTSDIR}/lang/guile
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
    		mftrace:${PORTSDIR}/print/mftrace

OPTIONS=	WEBDOCS	"Build and install documentation" off

MAN1=		lilymidi.1 lilypond-book.1 lilypond-invoke-editor.1 \
		lilypond.1 lilysong.1 convert-ly.1 abc2ly.1 etf2ly.1 \
		midi2ly.1 musicxml2ly.1
INFO=		lilypond lilypond-internals lilypond-program lilypond-learning \
		music-glossary

USE_AUTOTOOLS=	autoconf:261
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	pango
INSTALLS_OMF=	yes
MAKEFILE=	GNUmakefile
BUILD_TARGET=	all
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" MAKEINFO="${LOCALBASE}/bin/makeinfo"

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
BUILD_DEPENDS+=	pbmpscale:${PORTSDIR}/graphics/netpbm
BUILD_TARGET+=	www
PLIST_SUB+=	DOCS=""
.else
PLIST_SUB+=	DOCS="@comment "
.endif

post-extract:
	( \
		${TAIL} -c+000000004597 ${DISTDIR}/${PORTNAME}-${PORTVERSION}-1.freebsd-x86.sh > \
		${WRKDIR}/${PORTNAME}.tmp.tar.bz2 && \
		${TAR} -xjf ${WRKDIR}/${PORTNAME}.tmp.tar.bz2 -C ${WRKDIR} && \
		${MKDIR} ${WRKSRC}/mf/out && \
		${CP} ${WRKDIR}/usr/share/lilypond/current/fonts/otf/*.otf ${WRKSRC}/mf/out \
	)

post-patch:
	${REINPLACE_CMD} -e 's|makeinfo|${LOCALBASE}/bin/makeinfo|' \
	    ${WRKSRC}/configure

post-install:
	${LN} -s ${DATADIR}/${PORTVERSION} ${DATADIR}/current
.if !defined(NOPORTDOCS) && defined(WITH_WEBDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/out-www/offline-root && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
