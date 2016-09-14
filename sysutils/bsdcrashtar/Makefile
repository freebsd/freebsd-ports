# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bsdcrashtar
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Archive FreeBSD kernel crash files

BROKEN=		Unfetchable (google code has gone away)

PLIST_FILES=	sbin/bsdcrashtar \
		man/man8/bsdcrashtar.8.gz

USES=		uidfix
MAKE_ENV+=	NO_OBJ=yes

.include <bsd.port.mk>
