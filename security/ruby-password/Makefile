# New ports collection makefile for:	Ruby/Password
# Date created:		18 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	password
PORTVERSION=	0.5.2
CATEGORIES=	security ruby
MASTER_SITES=	http://www.caliban.org/files/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to create, verify and manipulate passwords

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/termios.so:${PORTSDIR}/comms/ruby-termios

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_SHEBANG_FILES=	example/*

CONFIGURE_ARGS=	--with-crack-dict="${LOCALBASE}/libdata/cracklib/pw_dict.pwd"
INSTALL_TARGET=	site-install

MAN1=		pwgen.1
MANCOMPRESSED=	no

DOCS_EN=	CHANGES README

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/pwgen ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pwgen.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
