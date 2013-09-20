# Created by: ijliao
# $FreeBSD$

PORTNAME=	clpbar
PORTVERSION=	1.11.1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/bar-${PORTVERSION}
DISTNAME=	bar_${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Command Line Progress Bar

WRKSRC=		${WRKDIR}/bar-${PORTVERSION}
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CFLAGS+="${CFLAGS}"

MAN1=		bar.1
PLIST_FILES=	bin/bar

NO_STAGE=	yes
.include <bsd.port.mk>
