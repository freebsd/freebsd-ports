# Created by: Niek Bergboer <niek@bergboer.net>
# $FreeBSD$

PORTNAME=	birthday
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://users.zetnet.co.uk/mortia/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs reminders for upcoming events (e.g. birthdays)

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

PLIST_FILES=	bin/birthday man/man1/birthday.1.gz

USES=		gmake
MAKEFILE=	${WRKSRC}/Makefile.gnu
ALL_TARGET=	birthday
MAKE_ARGS=	CFLAGS="${CFLAGS} -DUNIX"

do-configure:
		cd ${WRKSRC} && ${MAKE} Makefile.gnu

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/birthday ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/birthday.man ${STAGEDIR}${MAN1PREFIX}/man/man1/birthday.1

.include <bsd.port.mk>
