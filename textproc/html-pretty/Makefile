# New ports collection makefile for:	html-pretty
# Date created:				16 March 2004
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	html-pretty
PORTVERSION=	1.01
CATEGORIES=	textproc www
MASTER_SITES=	http://www.math.utah.edu/pub/sgml/
DISTNAME=	htmlpty-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML and SGML prettyprinter and text-to-HTML/SGML converter

GNU_CONFIGURE=	yes

MAN1=		html-pretty.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*

DOCFILES=	AUTHORS BUGS COPYING ChangeLog NEWS README THANKS

post-install:
	-${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} ${WRKSRC}/*.html \
		${DOCSDIR}/html/
	${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} ${WRKSRC}/Docs/*.html \
		${DOCSDIR}/html/
	for docfile in ${DOCFILES}; do \
		${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} \
			${WRKSRC}/$$docfile ${DOCSDIR}/; \
	done
.endif

.include <bsd.port.mk>
