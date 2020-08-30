# Created by: ijliao
# $FreeBSD$

PORTNAME=	cave
PORTVERSION=	1.0b
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/bjk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character Animation Viewer for Everyone

LICENSE=	GPLv2+

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS="${LDFLAGS} -lncurses"
CPPFLAGS+=	-I${NCURSESINC} -I${LOCALBASE}/include

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/cave.1.gz

post-patch:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/doc/${PORTNAME}.1

.include <bsd.port.mk>
