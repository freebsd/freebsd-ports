# Created by: osa
# $FreeBSD$

PORTNAME=	seq2
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of the UNIX(tm) program called seq

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.1

PLIST_FILES=	bin/seq2 man/man1/seq2.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CC) -o|$$(CC) $$(CFLAGS) -o|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
