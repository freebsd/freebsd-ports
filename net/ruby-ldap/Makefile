# New ports collection makefile for:	Ruby/LDAP
# Date created:		25 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.2.1
CATEGORIES=	net ruby
MASTER_SITES=	http://kt-www.jaist.ac.jp:8000/~ttate/ftp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if !defined(WITHOUT_OPENLDAP1)
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=	${WRKDIR}/ruby-${PORTNAME}

# Configure options:
#   --with-ldap		specify the ldap directory
#   --with-ldap-incdir	specify the directory which contains ldap.h and lber.h
#   --with-ldap-libdir	specify the directory which contains ldap libraries
#   --with-netscape	specify this to use Netscape SDK
#   --with-openldap1	specify this to use OpenLDAP-1.x
#   --with-openldap2	specify this to use OpenLDAP-2.x
CONFIGURE_ARGS?=	--with-openldap1 --with-ldap="${LOCALBASE}"

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
