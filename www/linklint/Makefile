# New ports collection makefile for:	linklint
# Date created:				16 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	linklint
PORTVERSION=	2.3.5
CATEGORIES=	www
MASTER_SITES=	http://www.linklint.org/download/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl script that checks links on web sites

USE_PERL5_RUN=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/linklint
HTMLDOC=	bugs.html doc_index.html dot.gif hints.html howitworks.html \
		index.html inputs.html language.html license.html linklint.gif \
		new.html outputs.html
DOC=		CHANGES.txt
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL}|' \
		${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.for f in ${HTMLDOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.mk>
