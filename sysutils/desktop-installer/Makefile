# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	desktop-installer
PORTVERSION=	0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Quickly configure a FreeBSD desktop system

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	auto-admin>=0.3.7:sysutils/auto-admin

USES=		tar:xz

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/Doc/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -r ${WRKSRC}/Data/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/Scripts
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${STAGEDIR}${DATADIR}/Scripts

.include <bsd.port.mk>
