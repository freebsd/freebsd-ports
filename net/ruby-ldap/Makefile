# New ports collection makefile for:	Ruby/LDAP
# Date created:		25 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby interface to LDAP API based on RFC1823

WITH_LDAP_BACKEND?=	openldap2

.if ${WITH_LDAP_BACKEND} == ldapsdk
LIB_DEPENDS=	${LOCALBASE}/mozilla/directory/lib/libldap.so.1:${PORTSDIR}/net/ldapsdk
.else
USE_OPENLDAP=	yes
.endif

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

.include <bsd.port.pre.mk>

# Configure options:
#   --with-ldap		specify the ldap directory
#   --with-ldap-incdir	specify the directory which contains ldap.h and lber.h
#   --with-ldap-libdir	specify the directory which contains ldap libraries
#   --with-netscape	specify this to use Netscape SDK
#   --with-openldap2	specify this to use OpenLDAP-2.x
.if ${WITH_LDAP_BACKEND} == openldap2
USE_OPENSSL=		yes
CONFIGURE_ARGS?=	--with-openldap2 \
			--with-ldap-dir="${LOCALBASE}"
.elif ${WITH_LDAP_BACKEND} == ldapsdk
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
