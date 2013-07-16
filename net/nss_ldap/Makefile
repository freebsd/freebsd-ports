# Created by: Jacques Vidrine <nectar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss_ldap
PORTVERSION=	1.${NSS_LDAP_VERSION}
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://www.padl.com/download/ \
		LOCAL/martymac
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	RFC 2307 NSS module

LICENSE=	GPLv2

NSS_LDAP_VERSION=265

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake aclocal autoconf autoheader
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

OPTIONS_DEFINE=	LCLASS KERBEROS
OPTIONS_DEFAULT=LCLASS KERBEROS

LCLASS_DESC=	Enable login classes via the loginClass attribute

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-rpath,${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-ldap-conf-file=${PREFIX}/etc/nss_ldap.conf \
		--with-ldap-secret-file=${PREFIX}/etc/nss_ldap.secret \
		--enable-rfc2307bis \
		--enable-paged-results

MAN5=	nss_ldap.5

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=--enable-configurable-krb5-ccname-env
.endif

.if ${PORT_OPTIONS:MLCLASS}
CFLAGS+="-DHAVE_LOGIN_CLASSES"
.endif

post-extract:
	${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/ldap\.,${PREFIX}/etc/nss_ldap.,g' \
		-e 's,/etc/openldap/ldap\.,${PREFIX}/etc/openldap/ldap.,g' \
		${WRKSRC}/ldap.conf
	@${REINPLACE_CMD} 's,#!/usr/bin/perl,#!${PERL},' \
		${WRKSRC}/vers_string
	@${REINPLACE_CMD} 's,/etc/ldap\.,${PREFIX}/etc/nss_ldap.,g' \
		${WRKSRC}/${MAN5}

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
	${INSTALL_MAN} ${WRKSRC}/${MAN5} ${MAN5PREFIX}/man/man5

post-install:
	@if [ ! -f ${PREFIX}/etc/nss_ldap.conf ]; then \
		${CP} -pv ${PREFIX}/etc/nss_ldap.conf.sample ${PREFIX}/etc/nss_ldap.conf ; \
	fi
.if !defined(PACKAGE_BUILDING)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
