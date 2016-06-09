# $FreeBSD$

PORTNAME=	openntpd
PORTVERSION=	6.0p1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon

LICENSE=	ISCL

USERS=		_ntp
GROUPS=		_ntp

USE_RC_SUBR=	openntpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

OPTIONS_DEFINE=		RESSL
RESSL_DESC=		SSL/TLS support via LibreSSL

OPTIONS_DEFAULT=	RESSL

# Requires libtls from LibreSSL
RESSL_USE=		openssl=yes
RESSL_VARS=		with_openssl_port=yes \
			openssl_port=security/libressl
RESSL_CONFIGURE_WITH=	cacert=${LOCALBASE}/etc/ssl/cert.pem
RESSL_CPPFLAGS=		-I${LOCALBASE}/include
RESSL_LDFLAGS=		-L${LOCALBASE}/lib
RESSL_RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/src/ntpd.conf.5 ${WRKSRC}/src/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} ntpd.conf ntpd.conf.sample

.include <bsd.port.mk>
