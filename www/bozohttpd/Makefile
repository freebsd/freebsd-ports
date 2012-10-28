# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	bozohttpd
PORTVERSION=	20100920
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/ \
		${MASTER_SITE_NETBSD}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	The bozotic HTTP server

LICENSE=	BSD

USE_BZIP2=	YES
USE_RC_SUBR=	bozohttpd

#options handling
OPTIONS_DEFINE=		HTPASSWD SSL CGI
OPTIONS_DEFAULT=	SSL CGI

HTPASSWD_DESC=		Enable htpassword support
SSL_DESC=		Enable SSL support
CGI_DESC=		Enable CGI support

#make happy portlint
.if empty(PORT_OPTIONS:MSSL)
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTPASSWD}
CFLAGS+=	-DDO_HTPASSWD
MAKE_ARGS+=	'LDFLAGS+= -lcrypt'
.else
CFLAGS+=	-UDO_HTPASSWD
.endif

.if ${PORT_OPTIONS:MSSL}
CFLAGS+=	-UNO_SSL_SUPPORT
.else
CFLAGS+=	-DNO_SSL_SUPPORT
.endif

.if ${PORT_OPTIONS:MCGI}
CFLAGS+=	-UNO_CGIBIN_SUPPORT
.else
CFLAGS+=	-DNO_CGIBIN_SUPPORT
.endif

MAN8=		bozohttpd.8
MANCOMPRESSED=	maybe
PLIST_FILES=	libexec/bozohttpd

post-patch:
	@${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/bozohttpd.8

.include <bsd.port.mk>
