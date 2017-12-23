# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	apsfilter
PORTVERSION=	7.2.8
PORTREVISION=	21
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/
DIST_SUBDIR=	apsfilter

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Magic print filter with print preview, duplex printing, and more

LICENSE=	PCL
LICENSE_NAME=	Postcard License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	bash:shells/bash \
		hpijs:print/hpijs

USES=		tar:bzip2
USE_SUBMAKE=	yes
WRKSRC=		${WRKDIR}/apsfilter
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=DOCS X11 GS PSUTILS ASCII CONVERT DVIPS FIG2DEV HTML2PS \
	ATALK SAMBA COMPRESS MP3 OGG WAV
OPTIONS_DEFAULT=X11 GS PSUTILS ASCII CONVERT A4
OPTIONS_SINGLE=PAPERSIZE
OPTIONS_SINGLE_PAPERSIZE=A4 LETTER LETTERDJ
NO_OPTIONS_SORT=yes
PAPERSIZE_DESC=	papersize
A4_DESC=	A4 papersize
LETTER_DESC=	letter papersize
LETTERDJ_DESC=	letter + special Deskjet adjectments
GS_DESC=	Postscript for non-PS printer
PSUTILS_DESC=	for pseudo duplex printing + paper handling
ASCII_DESC=	ASCII files in different styles/orientation
CONVERT_DESC=	support for lots of graphic file formats
DVIPS_DESC=	TeX DVI files
FIG2DEV_DESC=	XFIG drawings
HTML2PS_DESC=	HTML documents
ATALK_DESC=	remote printing on AppleTalk remote printer
SAMBA_DESC=	remote printing on Windows remote printer
COMPRESS_DESC=	print compressed documents

DOCS_MAKE_ARGS=	-DDOCS
PORTDOCS=	ANNOUNCE FAQ HOWTO-BUGREPORTS apsfilter4.png \
		README.BSD handbook.html README.TeX paper
GS_USES=	ghostscript:run
SAMBA_USES=	samba:run

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MX11)
# XXX Hack.  If you've done something like "-DWITHOUT_X11" on the command line
# (instead of WITHOUT_X11=true, or similar) gmake won't pick it up.  So make
# sure that NO_X is defined *and* has a value.
MAKE_ENV+=	NO_X=true
# ghostscript.mk USES doesn't check PORT_OPTIONS:MX11, so set this manualy
# so it selects the nox11 gs port
WITHOUT_X11=	yes
.endif

# hint: for batch mode you can now draw the following decisions
# - <default>		build and install most important filter utilities
#			that don't require X
# - APSFILTER_ALL	build and install all supported filter utilities

.if !empty(PORT_OPTIONS:MA4)
PSUFX=	-a4
.elif !empty(PORT_OPTIONS:MLETTER)
PSUFX=	-letter
.elif !empty(PORT_OPTIONS:MLETTERDJ)
PSUFX=	-letterdj
.endif

_DEPENDS_ASCII=	a2ps:print/a2ps \
		enscript:print/enscript${PSUFX} \
		mpage:print/mpage \
		recode:converters/recode
_DEPENDS_COMPRESS= \
		melt:archivers/freeze \
		lzop:archivers/lzop \
		arc:archivers/arc \
		cabextract:archivers/cabextract \
		lha:archivers/lha \
		rar:archivers/rar \
		rpm:archivers/rpm4 \
		unarj:archivers/unarj \
		zoo:archivers/zoo
_DEPENDS_PSUTILS= \
		psnup:print/psutils \
		fitstopnm:graphics/netpbm \
		htmldoc:textproc/htmldoc
_DEPENDS_CONVERT= \
		convert:graphics/ImageMagick \
		wmf2eps:graphics/libwmf \
		tgif:graphics/tgif \
		transfig:print/transfig
# XXX: recent versions of skencil do not include sk2ps.
#		sk2ps:graphics/skencil
_DEPENDS_DVIPS=	dvips:print/dvipsk-tetex
_DEPENDS_FIG2DEV= \
		fig2dev:print/transfig
_DEPENDS_HTML2PS= \
		html2ps:print/html2ps
_DEPENDS_ATALK=	pap:net/netatalk
_DEPENDS_MP3=	mpg321:audio/mpg321
_DEPENDS_OGG=	ogg123:audio/vorbis-tools
_DEPENDS_WAV=	wavplay:audio/wavplay

.for D in ${OPTIONS_DEFINE:NCONVERT}
.if (!empty(PORT_OPTIONS:M$D) || \
     (defined(BATCH) && defined(APSFILTER_ALL))) && \
    defined(_DEPENDS_$D)
RUN_DEPENDS+=	${_DEPENDS_$D}
.endif
.endfor
.if !empty(PORT_OPTIONS:MCONVERT) && !empty(PORT_OPTIONS:MX11) || \
    (defined(BATCH) && defined(APSFILTER_ALL))
RUN_DEPENDS+=	${_DEPENDS_CONVERT}
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/apsfilter/basedir
	${LN} -sfn ${PREFIX}/share/apsfilter ${STAGEDIR}${PREFIX}/etc/apsfilter/basedir

.include <bsd.port.mk>
