PORTNAME=	raptor
PORTVERSION=	1.4.21
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/librdf/${PORTNAME}/${PORTVERSION} \
		http://download.librdf.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland
WWW=		https://librdf.org/raptor/

DEPRECATED=	No new release in 10+ years and superseded by 2.0-branch, consider using textproc/raptor2
EXPIRATION_DATE=2023-09-30

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gnome libtool pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-html-dir=${PREFIX}/share/doc \
		--with-xml-parser=libxml --with-www=curl
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|utils ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
