# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	html2text
PORTVERSION=	1.3.2a
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.mbayer.de/html2text/downloads/
MASTER_SITE_SUBDIR=	apps/www/converters

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Converts HTML documents into plain text

LICENSE=	GPLv2

HAS_CONFIGURE=	yes

MANCOMPRESSED=	yes
MAN1=		html2text.1
MAN5=		html2textrc.5
PORTDOCS=	CHANGES CREDITS KNOWN_BUGS README TODO
PLIST_FILES=	bin/html2text

MAKE_JOBS_SAFE=	yes

CONFLICTS=	py27-html2text-[0-9]*

PORTSCOUT=	skipb:0 skipv:1.3.2

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/echo=/s/ -e//' ${WRKSRC}/configure
.for fle in Makefile.in libstd/Makefile.in
	@${REINPLACE_CMD} -e '/^DEBUG/s/^/#/; \
		 /^CXXFLAGS/s/=/+=/' ${WRKSRC}/${fle}
.endfor
.for fle in Area.h HTMLControl.h Properties.h format.h
	@${REINPLACE_CMD} -e 's/<istream>/<iostream>/' ${WRKSRC}/${fle}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1.gz ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.5.gz ${MANPREFIX}/man/man5
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for fle in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${fle} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
