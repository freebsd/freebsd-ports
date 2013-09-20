# Created by: Niek Bergboer <niek@bergboer.net>
# $FreeBSD$

PORTNAME=	birthday
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://users.zetnet.co.uk/mortia/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs reminders for upcoming events (e.g. birthdays)

MAN1=		birthday.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/birthday

USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/Makefile.gnu
ALL_TARGET=	birthday
MAKE_ARGS=	CFLAGS="${CFLAGS} -DUNIX"

NO_STAGE=	yes
do-configure:
		cd ${WRKSRC} && ${MAKE} Makefile.gnu

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/birthday ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/birthday.man ${MAN1PREFIX}/man/man1/birthday.1

.include <bsd.port.mk>
