# Ports collection Makefile for:	nss_ldap
# Date created:				4/1/2003
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nss_ldap
PORTVERSION=	1.${NSS_LDAP_VERSION}
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.padl.com/download/
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}

MAINTAINER=	nectar@FreeBSD.org
COMMENT=	RFC 2307 NSS module

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap20-client

NSS_LDAP_VERSION=204

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib"

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nss_ldap.so ${LOCALBASE}/lib/nss_ldap.so.1

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500112
IGNORE=		NSS modules only supported on FreeBSD 5.1 or later
.endif
.include <bsd.port.post.mk>
