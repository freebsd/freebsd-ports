# Created by: Daniel Harris <dannyboy@subdimension.com>
# $FreeBSD$

PORTNAME=	whowatch
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		PACKETSTORM/UNIX/IDS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays information in real time about users currently logged on

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/whowatch man/man1/${PORTNAME}.1.gz

pre-patch:
	@${FIND} ${WRKSRC} -name 'proc????.c' | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's/kp_.?proc\.._/ki_/ ; s/pcred\.p_//'

.include <bsd.port.mk>
