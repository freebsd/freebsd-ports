# New ports collection makefile for:	Yorick
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

# History: 1.4.1 port by Pedro Giffuni <giffunip@asme.org>
#          1.5.02 port by ports@FreeBSD.org,
#                 from submission by Ed Alley <wea@llnl.gov>
#          1.5.07 port by David H. Munro <munro1@llnl.gov>
# 1.5.07 notes:
# (1) info pages installed in PREFIX/info for consistency with other apps
#     -- really should be in PREFIX/share/info
# (2) several fixes to allow PREFIX for package install to be different
#     from PREFIX at build time (which is compiled into yorick and gist):
#     (a) PREFIX/bin/{yorick,gist} are softlinks, which allows
#         yorick and gist to compute ${PREFIX}/lib/${PORTNAME} at runtime
#     (b) softlink for g/ put in lib/${PORTNAME} for gist
#     (c) softlink doc/ so yorick online help is correct
#     (d) copy of paths.i put in lib/${PORTNAME}/bin for yorick
#     (e) pkg-install script added to fiddle softlinks, paths.i, and
#         Maketmpl if PREFIX has changed at install time
#     -- assume DOCSDIR and DATADIR take default values as does pkg-plist
#          1.5.08 replaces 1.5.07 infant mortality

PORTNAME=	yorick
PORTVERSION=	1.5.08
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/ \
		ftp://wuarchive.wustl.edu/languages/yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	munro1@llnl.gov

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_XLIB=	yes
MAKE_ARGS=	Y_HOME="${PREFIX}/lib/${PORTNAME}" Y_SITE="${DATADIR}" \
		Y_DOCDIR=/dev/null
MAN1=		yorick.1 gist.1

PORTDOCS=	FILE_FORMATS README drat.doc drat.tex graph.doc hex.doc \
		library.doc math.doc refs.pdf refs.ps refs.tex std.doc \
		yorick.pdf yorick.ps yorick.tex

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ysite config)

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; make yorick.info
	${GZIP_CMD} ${WRKSRC}/doc/yorick.info*
.endif

post-install:
.if !exists(${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/bin
.endif
.if !exists(${PREFIX}/man/man1)
	@${MKDIR} ${PREFIX}/man/man1
.endif
.for file in gist yorick
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.1 ${PREFIX}/man/man1
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/bin/${file}
	@${LN} -sf ${PREFIX}/lib/${PORTNAME}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/lib/codger
	${INSTALL_DATA} ${WRKSRC}/emacs/yorick.el ${DATADIR}
	@${LN} -sf ../../share/${PORTNAME}/g ${PREFIX}/lib/${PORTNAME}/g
	@${CP} ${DATADIR}/i0/paths.i ${PREFIX}/lib/${PORTNAME}/bin/paths.i
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${LN} -sf ../doc/${PORTNAME} ${DATADIR}/doc
.if !exists(${PREFIX}/info)
	@${MKDIR} ${PREFIX}/info
.endif
	for f in ${WRKSRC}/doc/yorick.info*; do \
	  ${INSTALL_DATA} $$f ${PREFIX}/info; \
	done
	install-info ${PREFIX}/info/yorick.info.gz ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
