# Created by: nrg milk <bsdports@gmail.com>
# $FreeBSD$

PORTNAME=	jfbterm
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=FreeBSD-
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ac.auone-net.jp/~baba/jfbterm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multilingual terminal emulator for framebuffer

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	requires VESA support in kernel

USES=		terminfo
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV+=	VERSION=${PORTVERSION} GUNZIP=${GUNZIP_CMD:N-*}
PLIST_SUB+=	TERMCAP_ADD_RECORD="@exec ${TERMCAP_ADD_RECORD:S,^${PREFIX},%D,}" \
		TERMCAP_DEL_RECORD="@unexec ${TERMCAP_DEL_RECORD}"

CAP_MKDB?=	/usr/bin/cap_mkdb
TERMINFO_FILE?=	${PREFIX}/share/misc/jfbterm.terminfo

OPTIONS_DEFINE=		ICONV PNG SETUID TERMCAP UNIFONT
OPTIONS_DEFAULT=	ICONV PNG SETUID TERMCAP UNIFONT
PNG_DESC=		Splash .png support
SETUID_DESC=		Install jfbterm with setuid bit set
TERMCAP_DESC=		Add entry to termcap(5) file
UNIFONT_DESC=		Install pan-unicode font

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSETUID}
PLIST_SUB+=	SETUID=""
.else
PLIST_SUB+=	SETUID="@comment "
.endif

.if !defined(INSTALL_AS_USER)
TERMCAP_FILE?=	/usr/share/misc/termcap
.else
TERMCAP_FILE?=	~/.termcap
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
.else
MAKE_ENV+=	WITHOUT_ICONV=
.endif

.if ${PORT_OPTIONS:MPNG}
. if !defined(NO_SHARED)
LIB_DEPENDS+=	libpng.so:graphics/png
. else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpng.a:graphics/png
. endif
.else
MAKE_ENV+=	WITHOUT_PNG=
.endif

.if ${PORT_OPTIONS:MTERMCAP}
TERMCAP_ADD_RECORD=	\
	${ECHO_CMD} '\# begin of jfbterm.termcap' \
		>>${TERMCAP_FILE}; \
	${CAT} ${PREFIX}/share/misc/jfbterm.termcap \
		>>${TERMCAP_FILE}; \
	${ECHO_CMD} '\# end of jfbterm.termcap' \
		>>${TERMCAP_FILE}; \
	if [ -f ${TERMCAP_FILE}.db ]; then \
		${CAP_MKDB} ${TERMCAP_FILE}; \
	fi
TERMCAP_DEL_RECORD=	\
	${REINPLACE_CMD} -i '' '/^\# begin of jfbterm\.termcap/, \
		/^\# end of jfbterm\.termcap/d' \
		${TERMCAP_FILE}; \
	if [ -f ${TERMCAP_FILE}.db ]; then \
		${CAP_MKDB} ${TERMCAP_FILE}; \
	fi
.else
TERMCAP_ADD_RECORD=	${DO_NADA}
TERMCAP_DEL_RECORD=	${DO_NADA}
.endif

.if ${PORT_OPTIONS:MUNIFONT}
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/gnu-unifont/unifont.pcf.gz:x11-fonts/gnu-unifont
.endif

post-extract:	.SILENT
	cd ${WRKSRC} && ${RM} -f \
		aclocal.m4 config.* configure install-sh \
		missing mkinstalldirs stamp-h* Makefile Makefile.in
	${CP} ${WRKSRC}/jfbterm.conf.sample.FreeBSD \
		${WRKSRC}/jfbterm.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		-e 's|\(share\)/jfbterm/\(fonts\)|\1/misc/\2|' \
		${WRKSRC}/*.[0-9] ${WRKSRC}/*.conf.sample

post-patch-TERMCAP-off:
	@${REINPLACE_CMD} '/^term/s/:.*/: xterm/' \
		${WRKSRC}/jfbterm.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jfbterm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jfbterm.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/jfbterm.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/jfbterm.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/termcap.jfbterm \
		${STAGEDIR}${PREFIX}/share/misc/jfbterm.termcap
	${INSTALL_DATA} ${WRKSRC}/terminfo.jfbterm \
		${STAGEDIR}${PREFIX}/share/misc/jfbterm.terminfo
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/misc/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/*.pcf.gz \
		${STAGEDIR}${PREFIX}/share/misc/fonts

.include <bsd.port.mk>
