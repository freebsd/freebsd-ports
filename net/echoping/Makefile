# Created by: peter
# $FreeBSD$

PORTNAME=	echoping
PORTVERSION=	6.0.2
PORTREVISION=	4
CATEGORIES=	net ipv6
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ping-like program that uses TCP and/or HTTP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libidn.so:dns/libidn

USES=		cpe libtool
CPE_VENDOR=	echoping_project
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE} \
		--enable-plugin="${PING_PLUGINS}"
INSTALL_TARGET=	install-strip

PING_PLUGINS=	dns random whois

OPTIONS_DEFINE=	LDAP PGSQL
OPTIONS_DEFAULT=LDAP
OPTIONS_SUB=	yes

LDAP_USE=	OPENLDAP=yes
LDAP_VARS=	PING_PLUGINS+=ldap

PGSQL_USES=	pgsql
PGSQL_VARS=	PING_PLUGINS+=postgresql

post-patch:
	@${REINPLACE_CMD} '/^echoping_LDADD =/s/$$/ -lm/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
