# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	5.3
CATEGORIES=	www
MASTER_SITES=	http://hiawatha.leisink.org/files/

MAINTAINER=	hugo@leisink.net
COMMENT=	An advanced and secure webserver for Unix

MAN1=		hiawatha.1 cgi_wrapper.1
MANCOMPRESSED=	no

USE_RC_SUBR=	hiawatha
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var webrootdir=${PREFIX}/www/hiawatha

OPTIONS=	SSL "Compile with SSL support?" On
OPTIONS+=	PHP "Include the CGI version of PHP?" On

CONFIG_FILES=	httpd.conf mimetype.conf throttle.conf cgi_wrapper.conf

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--disable-ssl
.endif

.if !defined(WITHOUT_PHP)
WANT_PHP_CGI=	yes
.endif

post-install:
	${CP} -f ${WRKSRC}/extra/fcgi-server ${PREFIX}/sbin
	${CP} -f ${WRKSRC}/extra/newroot ${PREFIX}/sbin
	@for _file in ${CONFIG_FILES} ; do \
		${CP} -f ${WRKSRC}/etc/hiawatha/$${_file} ${PREFIX}/etc/hiawatha/$${_file}.sample ; \
	done
	${CP} -f ${WRKSRC}/doc/index.html ${PREFIX}/www/hiawatha/index.html.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
