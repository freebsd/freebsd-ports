# New ports collection makefile for:	seq2
# Date created:				31 Oct 2003
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	seq2
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	http://www.referee.at/unix/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A clone of the UNIX(tm) program called seq

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.1

MAN1=		seq2.1
PLIST_FILES=	bin/seq2

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CC) -o|$$(CC) $$(CFLAGS) -o|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
