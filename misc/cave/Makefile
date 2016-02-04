# Created by: ijliao
# $FreeBSD$

PORTNAME=	cave
PORTVERSION=	1.0b
CATEGORIES=	misc
MASTER_SITES=	SF/bjk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character Animation Viewer for Everyone

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS="${LDFLAGS} -lncurses"

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/cave.1.gz

post-patch:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/doc/${PORTNAME}.1

.include <bsd.port.mk>
