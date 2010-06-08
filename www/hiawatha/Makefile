# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	7.3
CATEGORIES=	www
MASTER_SITES=	http://www.hiawatha-webserver.org/files/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	An advanced and secure webserver for Unix

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL
PORTEXAMPLES=	hiawatha mkcert newroot php-fcgi
CONFIG_FILES=	hiawatha.conf mimetype.conf cgi-wrapper.conf php-fcgi.conf
MAN1=		cgi-wrapper.1 hiawatha.1 newroot.1 php-fcgi.1 ssi-cgi.1 wigwam.1

USE_RC_SUBR=	hiawatha
SUB_FILES=	pkg-message
WANT_GNOME=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var webrootdir=${WWWDIR}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	COMMAND "Enable the Hiawatha CommandChannel" Off \
		CACHE "Internal file caching support" On \
		IPV6 "Enable IPv6 Support" On \
		MONITOR "Enable Hiawatha Monitor" On \
		SSL "Support for Secure Sockets Layer (SSL)" On \
		TOOLKIT "Enable URL Toolkit" On \
		XSLT "XSLT support" On

.include <bsd.port.pre.mk>

.if !defined(WITH_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !defined(WITH_CACHE)
CONFIGURE_ARGS+=	--disable-cache
.endif

.if !defined(WITH_TOOLKIT)
CONFIGURE_ARGS+=	--disable-toolkit
.endif

.if defined(WITH_COMMAND)
CONFIGURE_ARGS+=	--enable-command
.endif

.if !defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !defined(WITH_MONITOR)
CONFIGURE_ARGS+=	--disable-monitor
.endif

.if !defined(WITH_XSLT)
CONFIGURE_ARGS+=	--disable-xslt
.else
USE_GNOME+=	libxslt
CPPFLAGS+=	-I${LOCALBASE}/include/libxml2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/extra/,} ${EXAMPLESDIR}/
.endif
.for FILE in ${CONFIG_FILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/hiawatha/${FILE} ${PREFIX}/etc/hiawatha/${FILE}.sample
	@if [ ! -f ${PREFIX}/etc/hiawatha/${FILE} ]; then \
		${CP} -p ${WRKSRC}/etc/hiawatha/${FILE} ${PREFIX}/etc/hiawatha/${FILE} ; \
	fi
.endfor
	@if [ ! -d ${WWWDIR} ]; then \
		@${MKDIR} ${WWWDIR} ; \
	fi
	@${CP} ${WRKSRC}/doc/index.html ${WWWDIR}/index.hiawatha.html
	@if [ ! -f ${WWWDIR}/index.html ] ; then \
		${CP} ${WRKSRC}/doc/index.html ${WWWDIR}/ ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
