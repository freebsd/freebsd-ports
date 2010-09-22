# New ports collection makefile for:	jfbterm
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	jfbterm
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=${OPSYS}-
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ac.auone-net.jp/~baba/${PORTNAME}/ \
		http://chirashi-no-ura.net/files/

MAINTAINER=	bsdports@gmail.com
COMMENT=	Multilingual terminal emulator for framebuffer

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	requires VESA support in kernel

MAKE_JOBS_SAFE=	yes
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV+=	VERSION=${PORTVERSION} GUNZIP=${GUNZIP_CMD:N-*}
PLIST_SUB+=	TERMCAP_ADD_RECORD="@exec ${TERMCAP_ADD_RECORD}"

CAP_MKDB?=	/usr/bin/cap_mkdb

OPTIONS=	ICONV	"encodings support"		On \
		PNG	"splash .png support"		On \
		TERMCAP "add entry to termcap(5) file"	On \
		UNIFONT	"install pan-unicode font"	On

.if !defined(WITHOUT_SETUID)
BINMODE?=	4555
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800504
ONLY_FOR_ARCHS+=amd64
.endif

.if !defined(INSTALL_AS_USER)
TERMCAP_FILE?=	/usr/share/misc/termcap
.else
TERMCAP_FILE?=	~/.termcap
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1
MAN5=		${PORTNAME}.conf.5
.endif

.if defined(WITHOUT_ICONV)
MAKE_ENV+=	WITHOUT_ICONV=
.endif

.if !exists(/usr/include/iconv.h)
. if !defined(WITHOUT_ICONV)
.  if !defined(NO_SHARED)
USE_ICONV=	yes
.  else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libiconv.a:${PORTSDIR}/converters/libiconv
.  endif
. else
BUILD_DEPENDS+=	${LOCALBASE}/include/iconv.h:${PORTSDIR}/converters/libiconv
. endif
.endif

.if !defined(WITHOUT_PNG)
. if !defined(NO_SHARED)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
. else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
. endif
.else
MAKE_ENV+=	WITHOUT_PNG=
.endif

.if !defined(WITHOUT_TERMCAP)
TERMCAP_ADD_RECORD=	\
	if ${GREP} -q '^jfbterm|' ${TERMCAP_FILE}; then else \
		${CAT} ${PREFIX}/share/jfbterm/termcap.jfbterm \
			>>${TERMCAP_FILE}; \
		if [ -f ${TERMCAP_FILE}.db ]; then \
			${CAP_MKDB} ${TERMCAP_FILE}; \
		fi \
	fi
.else
TERMCAP_ADD_RECORD=	${DO_NADA}
.endif

.if !defined(WITHOUT_UNIFONT)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/local/unifont.pcf.gz:${PORTSDIR}/x11-fonts/gnu-unifont
.endif

post-extract:	.SILENT
	cd ${WRKSRC} && ${RM} -f \
		aclocal.m4 config.* configure install-sh \
		missing mkinstalldirs stamp-h* Makefile Makefile.in
	${CP} ${WRKSRC}/${PORTNAME}.conf.sample.${OPSYS} \
		${WRKSRC}/${PORTNAME}.conf.sample

post-patch:	.SILENT
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/*.[0-9] ${WRKSRC}/*.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc
	if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/${PORTNAME}.conf.sample \
			${PREFIX}/etc/${PORTNAME}.conf; \
	fi
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${MAN1PREFIX}/man/man5
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/termcap.jfbterm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/terminfo.jfbterm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.pcf.gz ${DATADIR}/fonts
.endif
.if !defined(WITHOUT_TERMCAP)
	${TERMCAP_ADD_RECORD}
.endif

.include <bsd.port.post.mk>
