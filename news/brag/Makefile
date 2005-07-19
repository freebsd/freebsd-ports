# New ports collection makefile for:	brag
# Date created:				19 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	brag
PORTVERSION=	1.4.1
CATEGORIES=	news tcl84
MASTER_SITES=	http://brag.sourceforge.net/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Download and assemble multipart binaries from newsgroups

RUN_DEPENDS=	uudeview:${PORTSDIR}/converters/uudeview \
		${TCLSH}:${PORTSDIR}/lang/tcl84

USE_REINPLACE=	yes

MAN1=		brag.1
PLIST_FILES=	bin/brag
PORTDOCS=	CHANGES README

TCLSH=		tclsh8.4

post-patch:
	@${REINPLACE_CMD} -e 's|^\(exec\ \)tclsh|\1${TCLSH}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
