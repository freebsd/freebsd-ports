PORTNAME=	link-grammar
DISTVERSION=	5.12.5
CATEGORIES=	textproc
MASTER_SITES=	https://www.gnucash.org/${PORTNAME}/downloads/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grammar checking library
WWW=		https://opencog.github.io/link-grammar-website/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib dos2unix gmake libtool localbase ncurses \
		pathfix pkgconfig sqlite
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode \
		--with-regexlib=pcre2 \
		--disable-python-bindings

INSTALL_TARGET=	install-strip

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		EDITLINE JAVA PERL SAT_SOLVER
OPTIONS_DEFAULT=	EDITLINE HUNSPELL SAT_SOLVER

OPTIONS_MULTI=			SPELL
OPTIONS_MULTI_SPELL=		ASPELL HUNSPELL

ASPELL_CONFIGURE_ENABLE=	aspell
ASPELL_LIB_DEPENDS=		libaspell.so:textproc/aspell

EDITLINE_CONFIGURE_ENABLE=	editline
EDITLINE_DESC=			Command line editing
EDITLINE_USES=			libedit

HUNSPELL_CONFIGURE_ENABLE=	hunspell
HUNSPELL_LIB_DEPENDS=		libhunspell-1.7.so:textproc/hunspell

JAVA_CONFIGURE_ENABLE=		java-bindings
JAVA_USES=			java
JAVA_CPPFLAGS=			-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd

PERL_CONFIGURE_ENABLE=		perl-bindings
PERL_LDFLAGS=			-L${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE -lperl
PERL_USES=			perl5

SAT_SOLVER_CONFIGURE_ENABLE=	sat-solver
SAT_SOLVER_DESC=		Use boolean SAT parser
SAT_SOLVER_LIB_DEPENDS=		libminisat.so:math/minisat

.include <bsd.port.mk>
