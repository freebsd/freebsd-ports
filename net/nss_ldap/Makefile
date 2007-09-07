# Ports collection Makefile for:	nss_ldap
# Date created:				4/1/2003
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nss_ldap
PORTVERSION=	1.${NSS_LDAP_VERSION}
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.padl.com/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}

MAINTAINER=	kazakov@gmail.com
COMMENT=	RFC 2307 NSS module

NSS_LDAP_VERSION=257

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

PLIST_FILES=	etc/nss_ldap.conf.sample lib/nss_ldap.so.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/nss_ldap.secret \
		--enable-rfc2307bis \
		--enable-schema-mapping \
		--enable-paged-results \
		--enable-configurable-krb5-ccname-env

MAN5=	nss_ldap.5

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nss_ldap.so ${PREFIX}/lib/nss_ldap.so.1
	${INSTALL_DATA} ${WRKSRC}/ldap.conf ${PREFIX}/etc/nss_ldap.conf.sample
	@${REINPLACE_CMD} 's,/etc/ldap.,${PREFIX}/etc/nss_ldap.,g' \
		${WRKSRC}/${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${MAN5PREFIX}/man/man5
	${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500112
IGNORE=		this NSS modules only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
