# New ports collection makefile for:	Ruby-SNMP
# Date created:		1 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	0.2.1
CATEGORIES=	net ruby
MASTER_SITES=	http://w3cic.riken.go.jp/~tsuruoka/
PKGNAMEPREFIX=	ruby-
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/ucd-snmp
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

WRKSRC=		${WRKDIR}/SNMP
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-snmp-dir="${LOCALBASE}"

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	mib_view.html \
		rubysnmp.html \
		sampleout.html \
		snmp_module.html \
		snmp_session.html \
		snmp_var.html

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/snmp
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/snmp/
.endfor
.endif

.include <bsd.port.mk>
