# New ports collection makefile for:	redland-bindings
# Date created:		2004-08-10
# Whom:			Russell Cloran <russell@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	redland-bindings
PORTVERSION=	1.0.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	russell@rucus.ru.ac.za
COMMENT=	Language bindings for the Redland package

BROKEN=		Configure fails
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

#OPTIONS=	JAVA "Add Java bindings" off \
#		PERL "Add Perl bindings" off \
#		PHP "Add PHP bindings" off \
#		PYTHON "Add Python bindings" off \
#		RUBY "Add Ruby bindings" off \
#		TCL "Add TCL bindings" off
LIB_DEPENDS=	rdf.0:${PORTSDIR}/textproc/redland
.if defined(WITH_JAVA)
BUILD_DEPENDS=	${LOCALBASE}/lib/librdf.la:${PORTSDIR}/textproc/redland
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_VESION=	1.3+
CONFIGURE_ARGS+=	--with-java --with-jdk=${JAVA_HOME}
PLIST_SUB+=	WITH_JAVA=""
.else
PLIST_SUB+=	WITH_JAVA="@comment "
.endif
.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=	WITH_PERL=""
MANPREFIX=	${LOCALBASE}/lib/perl5/${PERL_VER}
MAN3=	RDF::Redland.3 \
	RDF::Redland::Iterator.3 \
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
	RDF::Redland::URI.3
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
USE_PYTHON=	yes
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
.if defined(WITH_TCL)
.if defined(WITH_TCL83)
TCL_SHORT_V=	83
TCL_LONG_V=	8.3
.else
TCL_SHORT_V=	84
TCL_LONG_V=	8.4
.endif
PLIST_SUB+=	WITH_TCL=""
PLIST_SUB+=	TCL_DIR="lib/tcl/${TCL_LONG_V}"
CONFIGURE_ARGS+=	--with-tcltk=${LOCALBASE}/bin/tclsh${TCL_LONG_V}
LIB_DEPENDS+=	tcl${TCL_SHORT_V}:${PORTSDIR}/lang/tcl${TCL_SHORT_V}
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

GNU_CONFIGURE=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "**********************************************"
	@${ECHO_MSG} "The following make variables can be set to"
	@${ECHO_MSG} "enable bindings for various languages"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_JAVA   - Java bindings"
	@${ECHO_MSG} "WITH_PERL   - Perl module"
	@${ECHO_MSG} "WITH_PHP    - PHP extension"
	@${ECHO_MSG} "WITH_PYTHON - Python extension"
	@${ECHO_MSG} "WITH_RUBY   - Ruby bindings"
	@${ECHO_MSG} "WITH_TCL    - TCL bindings"
	@${ECHO_MSG} "**********************************************"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
