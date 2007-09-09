# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	5.11
CATEGORIES=	www
MASTER_SITES=	http://hiawatha.leisink.org/files/

MAINTAINER=	hugo@leisink.net
COMMENT=	An advanced and secure webserver for Unix

MAN1=		hiawatha.1 cgi-wrapper.1 php-fcgi.1 wigwam.1 newroot.1
MANCOMPRESSED=	no

USE_RC_SUBR=	hiawatha
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var webrootdir=${PREFIX}/www/hiawatha
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	SSL "Support for Secure Sockets Layer (SSL)?" On
OPTIONS+=	CACHE "Internal file caching support?" On
OPTIONS+=	COMMAND "Enable the Hiawatha CommandChannel?" Off

CONFIG_FILES=	httpd.conf mimetype.conf cgi-wrapper.conf php-fcgi.conf

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--disable-ssl
.endif

.if defined(WITHOUT_CACHE)
CONFIGURE_ARGS+=--disable-cache
.endif

.if defined(WITH_COMMAND)
CONFIGURE_ARGS+=--enable-command
.endif

post-install:
	@for file in ${CONFIG_FILES} ; do \
	    ${CP} -f ${WRKSRC}/etc/hiawatha/$${file} ${PREFIX}/etc/hiawatha/$${file}.sample ; \
	done
	${CP} -f ${WRKSRC}/doc/index.html ${PREFIX}/www/hiawatha/index.html.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
