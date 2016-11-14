# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	bozohttpd
PORTVERSION=	20130711
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/ \
		NETBSD

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	The bozotic HTTP server

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	bozohttpd

#options handling
OPTIONS_DEFINE=		HTPASSWD SSL CGI
OPTIONS_DEFAULT=	SSL CGI

SSL_USES=	ssl
SSL_CFLAGS=	-I${OPENSSLINC}
SSL_LDFLAGS=	-L${OPENSSLLIB}

USES=		cpe uidfix tar:bzip2
CPE_VENDOR=	eterna

HTPASSWD_DESC=		Enable htpassword support
CGI_DESC=		Enable CGI support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTPASSWD}
MAKE_ARGS+=	'COPTS+=	-DDO_HTPASSWD' \
		'LDFLAGS+= -lcrypt'
.else
MAKE_ARGS+=	'COPTS+=	-UDO_HTPASSWD'
.endif

.if ${PORT_OPTIONS:MSSL}
MAKE_ARGS+=	'COPTS+=	-UNO_SSL_SUPPORT'
.else
MAKE_ARGS+=	'COPTS+=	-DNO_SSL_SUPPORT' \
		'CRYPTOLIBS=' \
		'CRYPTODEPS='
.endif

.if ${PORT_OPTIONS:MCGI}
MAKE_ARGS+=	'COPTS+=	-UNO_CGIBIN_SUPPORT'
.else
MAKE_ARGS+=	'COPTS+=	-DNO_CGIBIN_SUPPORT'
.endif

PLIST_FILES=	libexec/bozohttpd \
		man/man8/bozohttpd.8.gz
post-patch:
	@${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/bozohttpd.8

.include <bsd.port.mk>
