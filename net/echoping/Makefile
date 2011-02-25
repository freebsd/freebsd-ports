# New ports collection makefile for:	echoping
# Date created:		13 April 1997
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	echoping
PORTVERSION=	6.0.0
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A ping-like program that uses tcp and/or http

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		idn.16:${PORTSDIR}/dns/libidn

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE}

PING_PLUGINS=	dns random whois

MAN1=		echoping.1 echoping_dns.1 echoping_random.1 echoping_whois.1

OPTIONS=	LDAP "Enable LDAP plug-in" on \
		PGSQL "Enable PostgreSQL plug-in" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc"
BROKEN=		Does not link on ia64 or powerpc
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
MAN1+=		echoping_ldap.1
PING_PLUGINS+=	ldap
PLIST_SUB=	WITH_LDAP=""
.else
PLIST_SUB=	WITH_LDAP="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MAN1+=		echoping_postgresql.1
PING_PLUGINS+=	postgresql
PLIST_SUB+=	WITH_PGSQL=""
.else
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

CONFIGURE_ARGS+=--enable-plugin="${PING_PLUGINS}"

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

.include <bsd.port.post.mk>
