# New ports collection makefile for:	Ruby/Password
# Date created:		18 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	password
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	security ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library to create, verify, and manipulate passwords

LIB_DEPENDS=	crack.10:${PORTSDIR}/security/cracklib
RUN_DEPENDS=	rubygem-ruby-termios>=0:${PORTSDIR}/comms/rubygem-ruby-termios

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_SHEBANG_FILES=	example/*
SADIR=	lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

CONFIGURE_ARGS=	--with-crack-dict="${LOCALBASE}/libdata/cracklib/pw_dict.pwd"
INSTALL_TARGET=	site-install

MAN1=		ruby-pwgen.1
MANCOMPRESSED=	no

DOCS_EN=	CHANGES README

post-patch:
	@${REINPLACE_CMD} -E -e 's,([^[:alpha:]]+)crack.h,\1packer.h,g' \
		${WRKSRC}/rbcrack.c ${WRKSRC}/extconf.rb

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/pwgen ${PREFIX}/bin/ruby-pwgen
	${INSTALL_MAN} ${WRKSRC}/pwgen.1 ${MANPREFIX}/man/man1/ruby-pwgen.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
