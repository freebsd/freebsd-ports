# New ports collection makefile for:	html2text
# Date created:		7 March 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	html2text
PORTVERSION=	1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://userpage.fu-berlin.de/~mbayer/tools/
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts HTML documents into plain text

HAS_CONFIGURE=	yes
MAKE_ARGS=	CXX="${CXX}"

MANCOMPRESSED=	yes
MAN1=		html2text.1
MAN5=		html2textrc.5
PORTDOCS=	CHANGES CREDITS KNOWN_BUGS README TODO
PLIST_FILES=	bin/html2text

post-patch:
	@${REINPLACE_CMD} -e '/echo=/s/ -e//' ${WRKSRC}/configure
.for file in Makefile.in libstd/Makefile.in
	@${REINPLACE_CMD} -e '/^DEBUG/s/^/#/; \
		 /^CXXFLAGS/s/=/+=/' ${WRKSRC}/${file}
.endfor
.for file in Area.h HTMLControl.h Properties.h format.h
	@${REINPLACE_CMD} -e 's/<istream>/<iostream>/' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1.gz ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5.gz ${MANPREFIX}/man/man5
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
