# Created by: domi@saargate.de
# $FreeBSD$

PORTNAME=	rand
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://bzflag.bz/~erik/files/ \
		http://elfga.com/~erik/files/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Utility to display files or streams in random order

LICENSE=	GPLv2

USES=	gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/rand man/man1/rand.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|}-R|}-L|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rand ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/rand.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
