# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlstarlet
PORTVERSION=	1.4.2
CATEGORIES=	textproc
MASTER_SITES=	SF/xmlstar/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Command Line XML Toolkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	libxslt
USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libxml-prefix=${LOCALBASE} \
		--with-libxslt-prefix=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--disable-static-libs
PLIST_FILES=	bin/xml man/man1/xmlstarlet.1.gz
PORTDOCS=	xmlstarlet.txt \
		xmlstarlet-man.xml \
		xmlstarlet-ug.html xmlstarlet-ug.pdf \
		xmlstarlet-ug.ps xmlstarlet-ug.xml \
		html.css
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
