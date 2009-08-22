# New ports collection makefile for:	Ruby/LDAP
# Date created:		25 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby interface to LDAP API based on RFC1823

WITH_LDAP?=	openldap2

.if ${WITH_LDAP} == openldap1
USE_OPENLDAP=	yes
WANT_OPENLDAP_VER=	12
.elif ${WITH_LDAP} == openldap2
USE_OPENLDAP=	yes
.elif ${WITH_LDAP} == ldapsdk
LIB_DEPENDS=	${LOCALBASE}/mozilla/directory/lib/libldap.so.1:${PORTSDIR}/net/ldapsdk
.else
IGNORE=		you should set WITH_LDAP variable to openldap1, openldap2 or ldapsdk
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include <bsd.port.pre.mk>

.if ${WITH_LDAP} == openldap2
. if exists(${LOCALBASE}/bin/ldapwhoami)
_OPENLDAP_VER!= ${LOCALBASE}/bin/ldapwhoami -VV 2>&1 | ${GREP} ldapwhoami | ${SED} -E 's/.*OpenLDAP: ldapwhoami (2)\.(3|4).*/\1\2/'
. endif

. if defined(_OPENLDAP_VER)
LDAPVER=	${_OPENLDAP_VER}
. elif defined(DEFAULT_OPENLDAP_VER)
LDAPVER=	${DEFAULT_OPENLDAP_VER}
. else
LDAPVER=	24
. endif
. if ${LDAPVER} == 24
EXTRA_PATCHES=	${FILESDIR}/extra::patch-ldap.c ${FILESDIR}/extra::patch-conn.c
. endif
.endif

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

DOCS_EN=	ChangeLog FAQ README TODO

post-patch:
	${RUBY} -i -pe 'gsub %r|/usr/local/openldap|, "${PREFIX}"' \
		-e 'gsub /ruby-1\.6/, "${RUBY}"' ${WRKSRC}/test/test.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${RUBY_MODDOCDIR}
	@(cd ${WRKSRC}/test/ && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/)
	@(cd ${WRKSRC}/example/ && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/)
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.post.mk>
