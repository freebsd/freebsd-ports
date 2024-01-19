PORTNAME=	rarian
DISTVERSION=	0.8.5
PORTREVISION=	6
CATEGORIES=	textproc gnome
MASTER_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/releases/${DISTVERSION}/downloads/assets/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	OMF help system based on the Freedesktop specification
WWW=		https://rarian.freedesktop.org/

LICENSE=	GPLv2+ LGPL21+ ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.UTILS
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB
LICENSE_FILE_ZLIB=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt \
		bash:shells/bash \
		xsltproc:textproc/libxslt \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt \
		bash:shells/bash \
		xsltproc:textproc/libxslt \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl

USES=		gmake libtool localbase pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-convert-dir=${LOCALBASE}/share/omf \
		--with-default-data-dirs="${LOCALBASE}/share:/usr/share" \
		--with-default-infopath="${LOCALBASE}/info:${LOCALBASE}/share/info" \
		--with-default-manpath="/usr/share/man:${LOCALBASE}/share/man:${LOCALBASE}/man" \
		--with-gnu-getopt=${LOCALBASE}/bin/getopt \
		--with-localstate-subdir=db/rarian \
		--with-metadata-dir=${DOCSDIR}

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|`getopt|`${LOCALBASE}/bin/getopt|' ${WRKSRC}/util/rarian-sk-update.in

.include <bsd.port.mk>
