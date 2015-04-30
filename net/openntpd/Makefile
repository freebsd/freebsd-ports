# $FreeBSD$

PORTNAME=	openntpd
PORTVERSION=	5.7p4
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenNTPD

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Network Time Protocol (NTP) daemon

LICENSE=	ISCL

USERS=		_ntp
GROUPS=		_ntp

USE_RC_SUBR=	openntpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

# XXX:
# * LibreSSL fails with the certificiate bundle from ca_root_nss.
# * USE_OPENSSL does not handle LibreSSL yet.
#
#OPTIONS_DEFINE=		RESSL
#RESSL_DESC=		SSL/TLS support via LibreSSL
#
#OPTIONS_DEFAULT=	RESSL
#
#RESSL_LIB_DEPENDS=	libtls.so:${PORTSDIR}/security/libressl
#RESSL_CONFIGURE_WITH=	cacert=${LOCALBASE}/etc/ssl/cert.pem
#RESSL_CPPFLAGS=		-I${LOCALBASE}/include
#RESSL_LDFLAGS=		-L${LOCALBASE}/lib

pre-build:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	    ${WRKSRC}/src/ntpd.conf.5 ${WRKSRC}/src/ntpd.8

post-install:
	cd ${STAGEDIR}${PREFIX}/etc; ${MV} ntpd.conf ntpd.conf.sample

.include <bsd.port.mk>
