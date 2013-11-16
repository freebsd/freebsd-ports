# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	tty-clock
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://github.com/xorg62/${PORTNAME}/tarball/
DISTNAME=	a82fd71
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal based clock

FETCH_ARGS=	-pRr
WRKSRC=		"${WRKDIR}/xorg62-${PORTNAME}-${DISTNAME}"
PLIST_FILES=	bin/tty-clock

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS \+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|LDFLAGS =|LDFLAGS \+=|' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tty-clock ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
