# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook2X
PORTVERSION=	0.8.8
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert DocBook documents into UNIX man page and GNU Texinfo formats

BUILD_DEPENDS=	p5-XML-NamespaceSupport>=0:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX-Expat>=0:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		libxslt>=0:${PORTSDIR}/textproc/libxslt \
		sdocbook-xml>=0:${PORTSDIR}/textproc/sdocbook-xml \
		dsssl-docbook-modular>=0:${PORTSDIR}/textproc/dsssl-docbook-modular \
		OpenSP>=0:${PORTSDIR}/textproc/opensp
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	docbook-utils-*

GNU_CONFIGURE=	yes
USES=		iconv gmake perl5
CONFIGURE_ENV=	PERL=${PERL}

OPTIONS_DEFINE=	DOCS

INFO=		docbook2X docbook2man-xslt docbook2texi-xslt

post-patch:
	@${REINPLACE_CMD} "s|\$${prefix}|${PREFIX}|" \
		${WRKSRC}/configure

.include <bsd.port.mk>
