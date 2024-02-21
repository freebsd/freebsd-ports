PORTNAME=	docbook2X
PORTVERSION=	0.8.8
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert DocBook documents into UNIX man page and GNU Texinfo formats
WWW=		https://docbook2x.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	OpenSP>=0:textproc/opensp \
		dsssl-docbook-modular>=0:textproc/dsssl-docbook-modular \
		p5-XML-NamespaceSupport>=0:textproc/p5-XML-NamespaceSupport \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-XML-SAX-Expat>=0:textproc/p5-XML-SAX-Expat \
		sdocbook-xml>=0:textproc/sdocbook-xml

USES=		gmake gnome iconv perl5
USE_GNOME=	libxslt

CONFIGURE_ENV=	PERL=${PERL}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		docbook2X docbook2man-xslt docbook2texi-xslt

CONFLICTS_INSTALL=	docbook-utils # bin/docbook2man bin/docbook2texi share/man/man1/docbook2man.1.gz share/man/man1/docbook2texi.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|$${prefix}|${PREFIX}|' ${WRKSRC}/configure

.include <bsd.port.mk>
