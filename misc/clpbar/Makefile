# Created by: ijliao

PORTNAME=	clpbar
PORTVERSION=	1.11.1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/bar-${PORTVERSION}
DISTNAME=	bar_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line Progress Bar

WRKSRC=		${WRKDIR}/bar-${PORTVERSION}
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CFLAGS+="${CFLAGS}"

CONFLICTS_INSTALL=	bar # bin/bar

PLIST_FILES=	bin/bar \
		man/man1/bar.1.gz

.include <bsd.port.pre.mk>

.if empty(ARCH:M*64)
CONFIGURE_ARGS=	--disable-use-m64
.endif

.include <bsd.port.post.mk>
