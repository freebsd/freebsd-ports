# New ports collection makefile for:	Yorick
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	yorick
PORTVERSION=	1.5.02
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/ \
		ftp://wuarchive.wustl.edu/languages/yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_XLIB=	yes
MAKE_ARGS=	Y_HOME="${PREFIX}/lib/${PORTNAME}" Y_SITE="${DATADIR}"
MAN1=		yorick.1 gist.1

PORTDOCS=	FILE_FORMATS README drat.doc drat.tex graph.doc hex.doc \
		library.doc math.doc refs.ps refs.tex std.doc yorick.pdf \
		yorick.ps yorick.tex

post-patch:
	@${PERL} -pi -e \
		's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/play/x11/xconfig.sh

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ysite config)

post-install:
.for file in gist yorick
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.1 ${PREFIX}/man/man1
	@strip ${PREFIX}/lib/${PORTNAME}/bin/${file}
	@${LN} -sf ${PREFIX}/lib/${PORTNAME}/bin/${file} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
