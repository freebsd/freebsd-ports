# Created by: hannes sowa <satbran@web.de>
# $FreeBSD$

PORTNAME=	vlog
PORTVERSION=	1.1f
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://inc2.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based real-time logfile viewer esp. useful for ipflog

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5 tar:tgz
USE_PERL5=	build
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS} -lcurses -pthread"
ALL_TARGET=	it

PLIST_FILES=	bin/vlog man/man1/vlog.1.gz

post-patch:
	@${REINPLACE_CMD} '/strip/d' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} vlog \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} vlog.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
