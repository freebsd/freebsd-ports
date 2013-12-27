# Created by: kaz
# $FreeBSD$

PORTNAME=	vrfy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://jadawin.tuxaco.net/freebsd/
DISTNAME=	${PORTNAME}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Verify mail address

WRKSRC=		${WRKDIR}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" RES=""
PLIST_FILES=	bin/vrfy

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vrfy ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
