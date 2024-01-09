PORTNAME=	birthday
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs reminders for upcoming events (e.g. birthdays)
WWW=		https://sourceforge.net/projects/birthday/

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

USES=		gmake tar:bzip2

ALL_TARGET=	birthday
MAKE_ARGS=	CFLAGS="${CFLAGS} -DUNIX"

PLIST_FILES=	bin/birthday share/man/man1/birthday.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/birthday ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/birthday.man \
		${STAGEDIR}${PREFIX}/share/man/man1/birthday.1

.include <bsd.port.mk>
