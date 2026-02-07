PORTNAME=	slowcgi
PORTVERSION=	7.1.20220916
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	FastCGI interface for old CGI programs
WWW=		https://github.com/koue/slowcgi

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	koue
GH_PROJECT=	slowcgi

USE_RC_SUBR=	slowcgi

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/share/man/man

CFLAGS+=	-Wall -I${PREFIX}/include

LDFLAGS+=	-L${PREFIX}/lib

WRKSRC_SUBDIR=	src/usr.sbin/${GH_PROJECT}

USERS=		www
GROUPS=		www

PLIST_FILES=	sbin/slowcgi \
		share/man/man8/slowcgi.8.gz

.include <bsd.port.mk>
