# Ports collection Makefile for:	nss_ldap
# Date created:				4/1/2003
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nss_ldap
PORTVERSION=	1.${NSS_LDAP_VERSION}
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.padl.com/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}

MAINTAINER=	kazakov@gmail.com
COMMENT=	RFC 2307 NSS module

USE_OPENLDAP=	yes

NSS_LDAP_VERSION=249

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/nss_ldap.secret \
		--enable-rfc2307bis \
		--enable-schema-mapping \
		--enable-paged-results

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nss_ldap.so ${PREFIX}/lib/nss_ldap.so.1
	${INSTALL_DATA} ${WRKSRC}/ldap.conf ${PREFIX}/etc/nss_ldap.conf.sample
	${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500112
IGNORE=		NSS modules only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
