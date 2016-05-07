# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	password
PORTVERSION=	0.5.3
PORTREVISION=	7
CATEGORIES=	security ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library to create, verify, and manipulate passwords

OPTIONS_DEFINE=	DOCS EXAMPLES
LIB_DEPENDS=	libcrack.so:security/cracklib
RUN_DEPENDS=	rubygem-ruby-termios>=0:comms/rubygem-ruby-termios

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

USE_RUBY=	yes
USES=		shebangfix
USE_RUBY_EXTCONF=	yes
SHEBANG_FILES=	example/*
SADIR=	lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

CONFIGURE_ARGS=	--with-crack-dict="${LOCALBASE}/libdata/cracklib/cracklib-words.pwd"
INSTALL_TARGET=	site-install
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

DOCS_EN=	CHANGES README
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}
DOCSDIR=	${RUBY_MODDOCDIR}
PORTEXAMPLES=	*
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -E -e 's,([^[:alpha:]]+)crack.h,\1packer.h,g' \
		${WRKSRC}/rbcrack.c ${WRKSRC}/extconf.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/pwgen ${STAGEDIR}${PREFIX}/bin/ruby-pwgen
	${INSTALL_MAN} ${WRKSRC}/pwgen.1 ${STAGEDIR}${MANPREFIX}/man/man1/ruby-pwgen.1
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
