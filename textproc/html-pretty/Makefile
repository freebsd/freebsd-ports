PORTNAME=	html-pretty
PORTVERSION=	1.02
CATEGORIES=	textproc www
MASTER_SITES=	http://ftp.math.utah.edu:80/pub/sgml/
DISTNAME=	htmlpty-${PORTVERSION}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	HTML and SGML prettyprinter and text-to-HTML/SGML converter
WWW=		http://www.math.utah.edu/~beebe/software/html-sgml-tools.html #html-pretty

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
