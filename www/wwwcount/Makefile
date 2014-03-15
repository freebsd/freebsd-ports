# Created by: ache
# $FreeBSD$

PORTNAME=	wwwcount
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.muquit.com/muquit/software/Count/src/wwwcount2.5/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	michael@ranner.eu
COMMENT=	Access counter, clock and date for WWW pages

GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes
USES=		gmake
MAN1=		mkstrip.1

NO_STAGE=	yes
pre-configure:
	cd ${WRKSRC}; PREFIX=${PREFIX} ./Count-config

post-build:
	cd ${WRKSRC}; ./Gen-conf

do-install:
	cd ${WRKSRC}; yes "" | ./Count-install
	cd ${WRKSRC}/utils/extdgts; \
		${INSTALL_PROGRAM} extdgts ${PREFIX}/bin;
	cd ${WRKSRC}/utils/mkstrip; \
		${INSTALL_PROGRAM} mkstrip ${PREFIX}/bin; \
		${INSTALL_MAN} mkstrip.1 ${PREFIX}/man/man1; \
		${INSTALL_SCRIPT} mkstrip.sh ${PREFIX}/lib/Counter/digits

.include <bsd.port.mk>
