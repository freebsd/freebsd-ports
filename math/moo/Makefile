# Created by: Steven Kreuzer <skreuzer@f2o.org>
# $FreeBSD$

PORTNAME=	moo
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	http://www.cyth.net/~ray/moo/ \
		http://www.exit2shell.com/~skreuzer/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Calculator that accepts C-like syntax as input

PLIST_FILES=	bin/moo
MAN1=		moo.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/moo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
