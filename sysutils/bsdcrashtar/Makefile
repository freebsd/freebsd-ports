PORTNAME=	bsdcrashtar
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive FreeBSD kernel crash files
WWW=		https://code.google.com/archive/p/bsdcrashtar/

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_GITHUB=	yes

GH_ACCOUNT=	trociny

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man
MAKE_ENV+=	NO_OBJ=yes

PLIST_FILES=	sbin/bsdcrashtar \
		share/man/man8/bsdcrashtar.8.gz

.include <bsd.port.mk>
