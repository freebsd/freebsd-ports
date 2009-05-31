# New ports collection makefile for:   hiawatha
# Date created:        24 november 2006
# Whom:                Hugo Leisink <hugo@leisink.net>
#
# $FreeBSD$
#

PORTNAME=	hiawatha
PORTVERSION=	6.13
CATEGORIES=	www
MASTER_SITES=	http://www.hiawatha-webserver.org/files/

MAINTAINER=	hugo@leisink.net
COMMENT=	An advanced and secure webserver for Unix

DOCS=		AUTHORS COPYING ChangeLog INSTALL
EXAMPLES=	hiawatha mkcert newroot php-fcgi
CONFIG_FILES=	httpd.conf mimetype.conf cgi-wrapper.conf php-fcgi.conf
MAN1=		cgi-wrapper.1 hiawatha.1 newroot.1 php-fcgi.1 wigwam.1
MANCOMPRESSED=	no

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
		IPV6 "Enable IPv6 Support" Off \
		SSL "Support for Secure Sockets Layer (SSL)" On \
		TOOLKIT "Enable URL Toolkit" On \
		XSLT "XSLT support" Off

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

.if defined(WITH_XSLT)
CONFIGURE_ARGS+=	--enable-xslt
USE_GNOME+=	libxslt
CPPFLAGS+=	-I${LOCALBASE}/include/libxml2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR} ${ETCDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/extra/,} ${EXAMPLESDIR}/
.endif
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/doc/,} ${MAN1PREFIX}/man/man1/
	@${INSTALL_DATA} ${CONFIG_FILES:S,^,${WRKSRC}/etc/${PORTNAME}/,} ${ETCDIR}/
	@${MKDIR} ${WWWDIR}
	@${CP} -f ${WRKSRC}/doc/index.html ${WWWDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
