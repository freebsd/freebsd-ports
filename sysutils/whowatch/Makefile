PORTNAME=	whowatch
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		PACKETSTORM/UNIX/IDS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays information in real time about users currently logged on
WWW=		http://wizard.ae.krakow.pl/~mike/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/whowatch share/man/man1/${PORTNAME}.1.gz

pre-patch:
	@${FIND} ${WRKSRC} -name 'proc????.c' | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's/kp_.?proc\.._/ki_/ ; s/pcred\.p_//'

.include <bsd.port.mk>
