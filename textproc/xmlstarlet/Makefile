PORTNAME=	xmlstarlet
DISTVERSION=	1.6.1
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/xmlstar/${PORTNAME}/${DISTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Command Line XML Toolkit
WWW=		https://xmlstar.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gnome iconv pkgconfig
USE_GNOME=	libxml2 libxslt

GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-incompatible-function-pointer-types

PLIST_FILES=	bin/xml \
		share/man/man1/xmlstarlet.1.gz

PORTDOCS=	xmlstarlet.txt \
		xmlstarlet-man.xml \
		xmlstarlet-ug.html xmlstarlet-ug.pdf \
		xmlstarlet-ug.ps xmlstarlet-ug.xml \
		html.css

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/ATTRIBUTE_UNUSED/__attribute__((unused))/g' \
	    ${PATCH_WRKSRC}/src/xml_pyx.c

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
