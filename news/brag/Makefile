# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	brag
PORTVERSION=	1.4.1
CATEGORIES=	news tcl
MASTER_SITES=	http://brag.sourceforge.net/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Download and assemble multipart binaries from newsgroups

RUN_DEPENDS=	uudeview:converters/uudeview \
		${TCLSH}:lang/tcl84

PLIST_FILES=	bin/brag man/man1/brag.1.gz
PORTDOCS=	CHANGES README

TCLSH=		tclsh8.4

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^\(exec\ \)tclsh|\1${TCLSH}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
