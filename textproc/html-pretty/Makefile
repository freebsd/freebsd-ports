# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	html-pretty
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://ftp.math.utah.edu:80/pub/sgml/
DISTNAME=	htmlpty-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML and SGML prettyprinter and text-to-HTML/SGML converter

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/Docs/*.html \
		${STAGEDIR}${DOCSDIR}/html
.for f in AUTHORS BUGS ChangeLog NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
