# Created by: Niek Bergboer <niek@bergboer.net>
# $FreeBSD$

PORTNAME=	birthday
PORTVERSION=	1.6.2
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs reminders for upcoming events (e.g. birthdays)

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

USES=		gmake tar:bzip2

ALL_TARGET=	birthday
MAKE_ARGS=	CFLAGS="${CFLAGS} -DUNIX"

PLIST_FILES=	bin/birthday man/man1/birthday.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/birthday ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/birthday.man \
		${STAGEDIR}${MAN1PREFIX}/man/man1/birthday.1

.include <bsd.port.mk>
