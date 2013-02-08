# Created by: Russell Cloran <russell@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	redland-bindings
PORTVERSION=	1.0.16.1
CATEGORIES?=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER?=	kde@FreeBSD.org
COMMENT?=	Language bindings for the Redland package

LIB_DEPENDS=	rdf:${PORTSDIR}/textproc/redland

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	PERL PHP PYTHON RUBY
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl
PLIST_SUB+=	WITH_PERL=""
MANPREFIX=	${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		RDF::Redland.3 \
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

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	yes
USE_PHP_BUILD=	yes
CONFIGURE_ARGS+=--with-php
PLIST_SUB+=	WITH_PHP=""
.else
PLIST_SUB+=	WITH_PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2.5+
CONFIGURE_ARGS+=--with-python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
CONFIGURE_ARGS+=--with-ruby
PLIST_SUB+=	WITH_RUBY=""
.else
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MPERL}
	-${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/mach/perllocal.pod
.endif

.include <bsd.port.mk>
