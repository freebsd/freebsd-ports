# New ports collection makefile for:	Ruby/LDAP
# Date created:		25 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.8.3
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
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

#WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog FAQ README TODO

post-patch:
	${RUBY} -i -pe 'gsub %r|/usr/local/openldap|, "${PREFIX}"' \
		-e 'gsub /ruby-1\.6/, "${RUBY}"' ${WRKSRC}/test/test.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/test/* ${WRKSRC}/example/* ${RUBY_MODEXAMPLESDIR}/
	${LN} -fs . ${RUBY_MODEXAMPLESDIR}/test
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
