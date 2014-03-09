# Created by: peter
# $FreeBSD$

PORTNAME=	echoping
PORTVERSION=	6.0.0
PORTREVISION=	4
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A ping-like program that uses TCP and/or HTTP

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		idn.17:${PORTSDIR}/dns/libidn

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE} \
		--enable-plugin="${PING_PLUGINS}"

PING_PLUGINS=	dns random whois

OPTIONS_DEFINE=	LDAP PGSQL
OPTIONS_DEFAULT=	LDAP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
MAN1+=		echoping_ldap.1
PING_PLUGINS+=	ldap
PLIST_SUB=	WITH_LDAP=""
.else
PLIST_SUB=	WITH_LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
MAN1+=		echoping_postgresql.1
PING_PLUGINS+=	postgresql
PLIST_SUB+=	WITH_PGSQL=""
.else
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc"
BROKEN=		Does not link on ia64 or powerpc
.endif

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

.include <bsd.port.post.mk>
