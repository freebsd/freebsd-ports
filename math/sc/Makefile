# New ports collection makefile for:	sc
# Date created:			30 July 1998
# Whom:				Heinz Tschabitscher
#
# $FreeBSD$
#

PORTNAME=	sc
PORTVERSION=	7.16
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/financial/spreadsheet

MAINTAINER=	johans@stack.nl
COMMENT=	A curses-based spreadsheet program

MAN1=		sc.1 psc.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^prefix=/s,=.*,=$${PREFIX},' \
		-e '/^CC=/s,=.*,=${CC},' \
		-e '/^CFLAGS=/s,=.*,=-DSYSV3 ${CFLAGS} -O0,' \
		-e '/^LIBDIR=/s,=.*,=${DATADIR},' \
		-e '/^YACC=/s,=.*,=${YACC},' \
		-e '/usr.bin.crypt/s,^# *,,' \
		-e '/mkdir.*plugins/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/^void/int/' ${WRKSRC}/crypt.c
	@${REINPLACE_CMD} -e '/flag.val/s/.*/#undef is_cleared/' ${WRKSRC}/sc.h

.include <bsd.port.post.mk>
