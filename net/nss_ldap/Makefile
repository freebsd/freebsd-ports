# Ports collection Makefile for:	nss_ldap
# Date created:				4/1/2003
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nss_ldap
PORTVERSION=	1.${NSS_LDAP_VERSION}
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.padl.com/download/
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}

MAINTAINER=	nectar@FreeBSD.org
COMMENT=	RFC 2307 NSS module

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap20-client

NSS_LDAP_VERSION=204

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib"

CONFIGURE_ARGS+= \
		--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/nss_ldap.secret \
		--enable-rfc2307bis \
		--enable-schema-mapping \
		--enable-paged-results

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

post-build:
	${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nss_ldap.so ${PREFIX}/lib/nss_ldap.so.1
	${INSTALL_DATA} ${WRKSRC}/ldap.conf ${PREFIX}/etc/nss_ldap.conf.sample
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500112
IGNORE=		NSS modules only supported on FreeBSD 5.1 or later
.endif
.include <bsd.port.post.mk>
