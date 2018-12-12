# $FreeBSD$

PORTNAME=	link-grammar
DISTVERSION=	5.4.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grammar checking library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive

USES=		autoreconf compiler:c++11-lib dos2unix gmake libtool localbase ncurses \
		pathfix pkgconfig sqlite  # autoreconf is due to this bug: https://github.com/opencog/link-grammar/issues/649
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

DOCS=		AUTHORS MAINTAINERS README

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DOCS EDITLINE JAVA PERL PYTHON SAT_SOLVER TOKENIZER
OPTIONS_DEFAULT=	EDITLINE HUNSPELL SAT_SOLVER

OPTIONS_MULTI=			SPELL
OPTIONS_MULTI_SPELL=		ASPELL HUNSPELL

ASPELL_CONFIGURE_ENABLE=	aspell
ASPELL_LIB_DEPENDS=		libaspell.so:textproc/aspell

EDITLINE_CONFIGURE_ENABLE=	editline
EDITLINE_DESC=			Command line editing
EDITLINE_USES=			libedit

HUNSPELL_CONFIGURE_ENABLE=	hunspell
HUNSPELL_LIB_DEPENDS=		libhunspell-1.6.so:textproc/hunspell

JAVA_CONFIGURE_ENABLE=		java-bindings
JAVA_USE=			JAVA
JAVA_CPPFLAGS=			-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd

PERL_CONFIGURE_ENABLE=		perl-bindings
PERL_LDFLAGS=			-L${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE -lperl
PERL_USES=			perl5

PYTHON_CONFIGURE_ENABLE=	python-bindings
PYTHON_USES=			python:2.7

SAT_SOLVER_CONFIGURE_ENABLE=	sat-solver
SAT_SOLVER_DESC=		Use boolean SAT parser
SAT_SOLVER_CFLAGS=		-I${LOCALBASE}/include/minisat  # see https://github.com/opencog/link-grammar/issues/648
SAT_SOLVER_LIB_DEPENDS=		libminisat.so:math/minisat

TOKENIZER_CONFIGURE_ENABLE=	regex-tokenizer
TOKENIZER_DESC=			Use the regex word splitter (a demo)
TOKENIZER_BROKEN=		Missing headers, see https://github.com/opencog/link-grammar/issues/646

post-extract:
	@${RM} -r ${STAGEDIR}${PREFIX}/link-grammar/minisat  # remove the bundled code

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblink-grammar.so.${DISTVERSION}  # see https://github.com/opencog/link-grammar/issues/645

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
