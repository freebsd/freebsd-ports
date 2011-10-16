# New ports collection makefile for:	redland-bindings
# Date created:		2004-08-10
# Whom:			Russell Cloran <russell@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	redland-bindings
PORTVERSION=	1.0.13.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Language bindings for the Redland package

LIB_DEPENDS=	rdf.0:${PORTSDIR}/textproc/redland

OPTIONS=	PERL "Add Perl bindings" off \
		PHP "Add PHP bindings" off \
		PYTHON "Add Python bindings" on \
		RUBY "Add Ruby bindings" off

GNU_CONFIGURE=	yes

#IGNORE=		does not compatible with redland-1.0.12

.include <bsd.port.options.mk>

.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=	WITH_PERL=""
MANPREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=	RDF::Redland.3 \
	RDF::Redland::BlankNode.3 \
	RDF::Redland::Iterator.3 \
	RDF::Redland::LiteralNode.3 \
	RDF::Redland::Model.3 \
	RDF::Redland::Node.3 \
	RDF::Redland::Parser.3 \
	RDF::Redland::Query.3 \
	RDF::Redland::QueryResults.3 \
	RDF::Redland::RSS.3 \
	RDF::Redland::Serializer.3 \
	RDF::Redland::Statement.3 \
	RDF::Redland::Storage.3 \
	RDF::Redland::Stream.3 \
	RDF::Redland::URI.3 \
	RDF::Redland::URINode.3 \
	RDF::Redland::XMLLiteralNode.3
.else
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITH_PHP)
USE_PHP=	yes
USE_PHP_BUILD=	yes
CONFIGURE_ARGS+=	--with-php
PLIST_SUB+=	WITH_PHP=""
.else
PLIST_SUB+=	WITH_PHP="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	2.5+
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if defined(WITH_RUBY)
USE_RUBY=	yes
CONFIGURE_ARGS+=	--with-ruby
PLIST_SUB+=	WITH_RUBY=""
.else
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.include <bsd.port.mk>
