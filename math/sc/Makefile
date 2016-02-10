# Created by: Heinz Tschabitscher
# $FreeBSD$

PORTNAME=	sc
PORTVERSION=	7.16
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SUNSITE/apps/financial/spreadsheet

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Curses-based spreadsheet program

USES=		ncurses

post-patch:
	@${REINPLACE_CMD} -e '/^prefix=/s,=.*,=$${PREFIX},' \
		-e '/^CC=/s,=.*,=${CC},' \
		-e '/^CFLAGS=/s,=.*,=-DSYSV3 ${CFLAGS} -O0,' \
		-e '/^LIBDIR=/s,=.*,=$${DESTDIR}${DATADIR},' \
		-e '/^MANDIR=/s,=,=$${DESTDIR},' \
		-e '/^EXDIR=/s,=.*,=$${DESTDIR}${PREFIX}/bin,' \
		-e '/^YACC=/s,=.*,=${YACC},' \
		-e '/usr.bin.crypt/s,^# *,,' \
		-e '/mkdir.*plugins/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/^void/int/' ${WRKSRC}/crypt.c
	@${REINPLACE_CMD} -e '/flag.val/s/.*/#undef is_cleared/' ${WRKSRC}/sc.h

.include <bsd.port.mk>
