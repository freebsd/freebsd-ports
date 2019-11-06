# $FreeBSD$

PORTNAME=	chk4mail
PORTVERSION=	2.28
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/chk4mail/ \
		ftp://mud.stack.nl/pub/chk4mail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quickly check multiple folders for new email

BROKEN=		unfetchable

PLIST_FILES=	bin/chk4mail bin/chkimap \
		man/man1/chk4mail.1.gz man/man1/chkimap.1.gz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-imap

.include <bsd.port.mk>
