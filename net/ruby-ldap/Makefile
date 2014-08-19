# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ldap
PORTVERSION=	0.9.10
PORTREVISION=	2
CATEGORIES=	net ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to LDAP API based on RFC1823

OPTIONS_DEFINE=	DOCS

WITH_LDAP_BACKEND?=	openldap2

.if ${WITH_LDAP_BACKEND} == ldapsdk
LIB_DEPENDS=	${LOCALBASE}/mozilla/directory/lib/libldap.so.1:${PORTSDIR}/net/ldapsdk
.else
USE_OPENLDAP=	yes
.endif

USES=	tar:bzip2
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

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
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	@(cd ${WRKSRC}/test/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/)
	@(cd ${WRKSRC}/example/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/)
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.post.mk>
