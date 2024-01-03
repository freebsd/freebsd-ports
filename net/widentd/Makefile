PORTNAME=	widentd
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://BSDforge.com/projects/source/net/widentd/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	RFC1413 auth/identd daemon providing a fixed fake reply
WWW=		https://BSDforge.com/projects/net/widentd/

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable

USES=		ncurses uidfix tar:xz
USE_RC_SUBR=	widentd
MAKE_ENV+=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/man/man" MK_WERROR=no

PLIST_FILES=	sbin/widentd man/man8/widentd.8.gz

.include <bsd.port.mk>
