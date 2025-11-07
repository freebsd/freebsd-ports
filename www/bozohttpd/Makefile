PORTNAME=	bozohttpd
DISTVERSION=	20240126
CATEGORIES=	www
MASTER_SITES=	http://eterna23.net/bozohttpd/

MAINTAINER=	cpetrik@proton.me
COMMENT=	Bozotic HTTP server from NetBSD
WWW=		http://eterna23.net/bozohttpd/

LICENSE=	BSD2CLAUSE

USES=		cpe uidfix tar:bzip2
CPE_VENDOR=	eterna
USE_RC_SUBR=	bozohttpd

MAKE_ARGS=	LDADD="${LIBS}"

PLIST_FILES=	bin/bozohttpd \
		share/man/man8/bozohttpd.8.gz

OPTIONS_DEFINE=		BLACKLIST CGI DAEMON DEBUG DIRINDEX\
			DYNAMIC HTPASSWD LUA SSL USER
OPTIONS_DEFAULT=	BLACKLIST CGI DAEMON DEBUG DIRINDEX\
			DYNAMIC HTPASSWD LUA SSL USER

BLACKLIST_DESC=		Report Unauthorized and Forbidden accesses to blacklistd
CGI_DESC=		Common Gateway Interface (CGI) support (-C, -c, -E, -e)
DAEMON_DESC=		Optional daemon mode (-b)
DEBUG_DESC=		Debug support (-d)
DIRINDEX_DESC=		Automatic directory index if index.html is missing (-X)
DYNAMIC_DESC=		Dynamic content based on file suffixes (-C, -M)
HTPASSWD_DESC=		Basic authentication with .htpasswd files
LUA_DESC=		Lua scripts for dynamic content (-L)
SSL_DESC=		SSL/TLS for HTTPS requests (-Z, -z)
USER_DESC=		Optional /~user transformation (-e, -p, -u)

BLACKLIST_CFLAGS_OFF=	-DNO_BLACKLIST_SUPPORT
BLACKLIST_LIBS=		-lblacklist
CGI_CFLAGS_OFF=		-DNO_CGIBIN_SUPPORT
DAEMON_CFLAGS_OFF=	-DNO_DAEMON_MODE
DEBUG_CFLAGS_OFF=	-DNO_DEBUG
DIRINDEX_CFLAGS_OFF=	-DNO_DIRINDEX_SUPPORT
DYNAMIC_CFLAGS_OFF=	-DNO_DYNAMIC_CONTENT
HTPASSWD_CFLAGS=	-DDO_HTPASSWD
HTPASSWD_LIBS=		-lcrypt
LUA_USES=		lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_CFLAGS_OFF=		-DNO_LUA_SUPPORT
LUA_LDFLAGS=		-L${LUA_LIBDIR}
LUA_LIBS=		-llua-${LUA_VER}
SSL_USES=		ssl
SSL_CFLAGS=		-I${OPENSSLINC}
SSL_CFLAGS_OFF=		-DNO_SSL_SUPPORT
SSL_LDFLAGS=		-L${OPENSSLLIB}
SSL_LIBS=		-lcrypto -lssl
USER_CFLAGS_OFF=	-DNO_USER_SUPPORT

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
CFLAGS+=	-DOPENSSL_API_COMPAT=0x10100000L
.endif

.include <bsd.port.mk>
