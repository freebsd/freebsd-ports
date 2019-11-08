# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/rarian/Makefile,v 1.12 2008/03/09 21:41:22 mezz Exp $

PORTNAME=	rarian
PORTVERSION=	0.8.1
PORTREVISION=	4
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OMF help system based on the Freedesktop specification

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/bin/getopt:misc/getopt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

DOCBOOK_VERSION=4.2

CONFLICTS=	scrollkeeper-[0-9]*

USES=		gmake gnome libtool pathfix python tar:bzip2
USE_GNOME=	libxslt
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-convert-dir=${LOCALBASE}/share/omf \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/rarian|/db/rarian|' \
		${WRKSRC}/util/Makefile.in
	@${REINPLACE_CMD} -e 's|@localstatedir@/lib/rarian|@localstatedir@/db/rarian|g ; \
		s|getopt|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/util/rarian-sk-config.in \
		${WRKSRC}/util/rarian-sk-extract.in \
		${WRKSRC}/util/rarian-sk-rebuild.in \
		${WRKSRC}/util/rarian-sk-update.in
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/librarian/rarian-main.c \
		${WRKSRC}/librarian/rarian-man.c \
		${WRKSRC}/librarian/rarian-info.c

.include <bsd.port.mk>
