PORTNAME=	bsdcrashtar
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Archive FreeBSD kernel crash files

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_GITHUB=	yes

GH_ACCOUNT=	trociny

MAKE_ENV+=	NO_OBJ=yes

PLIST_FILES=	sbin/bsdcrashtar \
		man/man8/bsdcrashtar.8.gz

.include <bsd.port.mk>
