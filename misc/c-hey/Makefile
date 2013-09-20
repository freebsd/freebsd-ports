# Created by: Philip Reynolds
# $FreeBSD$

PORTNAME=	c-hey
PORTVERSION=	2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.redbrick.dcu.ie/~c-hey/src.gzipped/
DISTNAME=	c-hey2.1

MAINTAINER=	philip.reynolds@gmail.com
COMMENT=	Terminal based instant messaging utility

GNU_CONFIGURE=	yes

MAN1=		c-hey.1
MLINKS=		c-hey.1 hey.1
PLIST_FILES=	bin/c-hey bin/hey

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
