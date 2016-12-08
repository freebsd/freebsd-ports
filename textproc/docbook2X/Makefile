# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook2X
PORTVERSION=	0.8.8
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert DocBook documents into UNIX man page and GNU Texinfo formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	OpenSP>=0:textproc/opensp \
		dsssl-docbook-modular>=0:textproc/dsssl-docbook-modular \
		p5-XML-NamespaceSupport>=0:textproc/p5-XML-NamespaceSupport \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-SAX-Expat>=0:textproc/p5-XML-SAX-Expat \
		sdocbook-xml>=0:textproc/sdocbook-xml
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS_INSTALL=	docbook-utils-*

OPTIONS_DEFINE=	DOCS

CONFIGURE_ENV=	PERL=${PERL}
GNU_CONFIGURE=	yes
USE_GNOME=	libxslt
USES=		gmake iconv perl5
WANT_GNOME=	yes

INFO=		docbook2X docbook2man-xslt docbook2texi-xslt

post-patch:
	@${REINPLACE_CMD} 's|$${prefix}|${PREFIX}|' ${WRKSRC}/configure

.include <bsd.port.mk>
