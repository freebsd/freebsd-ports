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

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	RFC 2307 NSS module

LICENSE=	GPLv2

NSS_LDAP_VERSION=265

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake aclocal autoconf autoheader
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

OPTIONS=	LCLASS "Enable login classes via the loginClass attribute" on

PLIST_FILES=	etc/nss_ldap.conf.sample \
		lib/nss_ldap.so.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/nss_ldap.secret \
		--enable-rfc2307bis \
		--enable-paged-results

MAN5=	nss_ldap.5

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
.if !defined(WITHOUT_KERBEROS)
CONFIGURE_ARGS+=--enable-configurable-krb5-ccname-env
.endif

.if defined(WITH_LCLASS)
CFLAGS+="-DHAVE_LOGIN_CLASSES"
.endif

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

# XXX: newer autoconf's rely on the compiler result, not the preprocessor
#      for checking headers, so the configure.in needs to be fixed upstream
#      to properly include dependencies
post-configure:
	@${ECHO} "#define HAVE_NETINET_IF_ETHER_H 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_NET_ROUTE_H 1" >> ${WRKSRC}/config.h
	@${ECHO} "#define HAVE_RESOLV_H 1" >> ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nss_ldap.so ${PREFIX}/lib/nss_ldap.so.1
	${INSTALL_DATA} ${WRKSRC}/ldap.conf ${PREFIX}/etc/nss_ldap.conf.sample
	@${REINPLACE_CMD} 's,/etc/ldap.,${PREFIX}/etc/nss_ldap.,g' \
		${WRKSRC}/${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${MAN5PREFIX}/man/man5

post-install:
.if !defined(PACKAGE_BUILDING)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
