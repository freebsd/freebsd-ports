PORTNAME=	unquote
PORTVERSION=	1.0.b4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/misc/unquote/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Execute a command with safely quoted arguments
WWW=		https://devel.ringlet.net/misc/unquote/

USES=		uidfix

PLIST_FILES=	bin/unquote share/man/man1/unquote.1.gz

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"
.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif
MAKE_ENV+=	NO_WDATE_TIME=yes

.include <bsd.port.mk>
