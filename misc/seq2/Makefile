# New ports collection makefile for:	seq2
# Date created:				31 Oct 2003
# Whom:					osa
#
# $FreeBSD$
#

PORTNAME=	seq2
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.referee.at/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the UNIX(tm) program called seq

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.1

MAN1=		seq2.1
PLIST_FILES=	bin/seq2

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CC) -o|$$(CC) $$(CFLAGS) -o|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
