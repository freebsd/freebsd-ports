# New ports collection makefile for:	Ruby/LDAP
# Date created:		25 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.3
CATEGORIES=	net ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp:8000/~ttate/ftp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

WITH_LDAP?=	openldap2

.if ${WITH_LDAP} == openldap1
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap
.elif ${WITH_LDAP} == openldap2
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2
.elif ${WITH_LDAP} == ldapsdk
LIB_DEPENDS=	${LOCALBASE}/mozilla/directory/lib/libldap.so.1:${PORTSDIR}/net/ldapsdk
.else
.error WITH_LDAP must be set to one of "openldap1", "openldap2" and "ldapsdk".
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

# Configure options:
#   --with-ldap		specify the ldap directory
#   --with-ldap-incdir	specify the directory which contains ldap.h and lber.h
#   --with-ldap-libdir	specify the directory which contains ldap libraries
#   --with-netscape	specify this to use Netscape SDK
#   --with-openldap1	specify this to use OpenLDAP-1.x
#   --with-openldap2	specify this to use OpenLDAP-2.x
.if ${WITH_LDAP} == openldap1
CONFIGURE_ARGS?=	--with-openldap1 \
			--with-ldap-dir="${LOCALBASE}"
.elif ${WITH_LDAP} == openldap2
USE_OPENSSL=		yes
CONFIGURE_ARGS?=	--with-openldap2 \
			--with-ldap-dir="${LOCALBASE}"
.elif ${WITH_LDAP} == ldapsdk
CONFIGURE_ARGS?=	--with-netscape \
			--with-ldap-dir="${LOCALBASE}/mozilla/directory"
.endif

INSTALL_TARGET=	site-install

DOCS_EN=	README		README.html
EXAMPLES_EN=	test1.rb	test2.rb	test3.rb	test4.rb	\
		test5.rb	test6.rb	test7.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/ldap
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/test/${f} ${RUBY_EXAMPLESDIR}/ldap/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/ldap
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/ldap/
.endfor
.endif

.include <bsd.port.mk>
