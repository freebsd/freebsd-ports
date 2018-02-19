# $FreeBSD$

PORTNAME=	link-grammar
PORTVERSION=	5.3.16
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grammar checking library

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive

USES=		autoreconf compiler:c++11-lib dos2unix gmake libtool localbase \
		pathfix pkgconfig sqlite

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

DOCS=		AUTHORS LICENSE MAINTAINERS README

OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	HUNSPELL
OPTIONS_DEFINE=		DOCS EDITLINE JAVA PERL PYTHON

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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
