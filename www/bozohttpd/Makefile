PORTNAME=	bozohttpd
PORTVERSION=	20210227
CATEGORIES=	www
MASTER_SITES=	http://www.eterna.com.au/bozohttpd/ \
		NETBSD

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Bozotic HTTP server from NetBSD

LICENSE=	BSD2CLAUSE

USES=		cpe uidfix tar:bzip2
CPE_VENDOR=	eterna

OPTIONS_DEFINE=		BLACKLIST CGI DAEMON DEBUG DIRINDEX\
			DYNAMIC HTPASSWD LUA SSL USER
OPTIONS_DEFAULT=	BLACKLIST CGI DAEMON DEBUG DIRINDEX\
			DYNAMIC HTPASSWD LUA SSL USER

BLACKLIST_DESC=		Report Unauthorized and Forbidden accesses to blacklistd
BLACKLIST_CFLAGS_OFF=	-DNO_BLACKLIST_SUPPORT
BLACKLIST_LIBS=		-lblacklist

CGI_DESC=		Common Gateway Interface (CGI) support (-C, -c, -E, -e)
CGI_CFLAGS_OFF=		-DNO_CGIBIN_SUPPORT

DAEMON_DESC=		Optional daemon mode (-b)
DAEMON_CFLAGS_OFF=	-DNO_DAEMON_MODE

DEBUG_DESC=		Debug support (-d)
DEBUG_CFLAGS_OFF=	-DNO_DEBUG

DIRINDEX_DESC=		Automatic directory index if index.html is missing (-X)
DIRINDEX_CFLAGS_OFF=	-DNO_DIRINDEX_SUPPORT

DYNAMIC_DESC=		Dynamic content based on file suffixes (-C, -M)
DYNAMIC_CFLAGS_OFF=	-DNO_DYNAMIC_CONTENT

HTPASSWD_DESC=		Basic authentication with .htpasswd files
HTPASSWD_CFLAGS=	-DDO_HTPASSWD
HTPASSWD_LIBS=		-lcrypt

LUA_DESC=		Lua scripts for dynamic content (-L)
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_CFLAGS_OFF=		-DNO_LUA_SUPPORT
LUA_LDFLAGS=		-L${LUA_LIBDIR}
LUA_LIBS=		-llua-${LUA_VER}
LUA_USES=		lua

SSL_DESC=		SSL/TLS for HTTPS requests (-Z, -z)
SSL_CFLAGS=		-I${OPENSSLINC}
SSL_CFLAGS_OFF=		-DNO_SSL_SUPPORT
SSL_LDFLAGS=		-L${OPENSSLLIB}
SSL_LIBS=		-lcrypto -lssl
SSL_USES=		ssl

USER_DESC=		Optional /~user transformation (-e, -p, -u)
USER_CFLAGS_OFF=	-DNO_USER_SUPPORT

.include <bsd.port.options.mk>

MAKE_ARGS=	LDADD="${LIBS}"

USE_RC_SUBR=	bozohttpd

PLIST_FILES=	bin/bozohttpd \
		man/man8/bozohttpd.8.gz

.include <bsd.port.mk>
