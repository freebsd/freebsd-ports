# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tcpwrap
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	security ruby
MASTER_SITES=	http://shugo.net/archive/ruby-tcpwrap/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TCP wrappers library for Ruby

LIB_DEPENDS=	libident.so:${PORTSDIR}/security/libident

OPTIONS_DEFINE=	DOCS

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
CONFIGURE_ARGS=	--with-libwrap-dir=/usr \
		--with-ident-dir="${LOCALBASE}"

INSTALL_TARGET=	site-install

DOCS_EN=	README.en	doc/tcpwrap.html.en
DOCS_JA=	README.ja	doc/tcpwrap.html.ja

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_EN} ${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_JA} ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
