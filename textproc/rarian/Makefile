# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/rarian/Makefile,v 1.12 2008/03/09 21:41:22 mezz Exp $

PORTNAME=	rarian
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	textproc gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OMF help system based on the Freedesktop specification

LICENSE=	GPLv2+ LGPL21+ ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.UTILS
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB
LICENSE_FILE_ZLIB=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		bash:shells/bash \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		bash:shells/bash \
		docbook-xml>0:textproc/docbook-xml

USES=		gmake gnome libtool localbase pathfix python tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	0mp
GH_TAGNAME=	00fa779
USE_GNOME=	libxslt
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

.include <bsd.port.mk>
