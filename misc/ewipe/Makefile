# New ports collection makefile for:	ewipe
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	ewipe
PORTVERSION=	1.2.0
CATEGORIES?=	misc tk82
MASTER_SITES=	http://www.jnet-jp.to/~sekisita/ewipe/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Tcl/tk-based presentation tool

.if defined(KANJI)
RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80
.else
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
.endif

NO_BUILD=	YES
TCLLIBS=	definefont.tcl edittable.tcl setpointer.tcl viewer.tcl tclIndex
MYPORTDOCS=	Changes.jp README README.jp dot.ewipe
EXAMPLES=	a1.gif a2.gif a3.gif a4.gif blue1.gif sample.ewp test.ewp \
		tutorial.ewp tutorial-e.ewp

.if defined(KANJI)
WISH=		${LOCALBASE}/bin/wish8.0jp
.else
WISH=		${LOCALBASE}/bin/wish8.2
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
		-e "s|%%WISH%%|${WISH}|g;" ${WRKSRC}/ewipe

do-install:
	@${MKDIR} ${PREFIX}/share/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
.for file in ${TCLLIBS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
