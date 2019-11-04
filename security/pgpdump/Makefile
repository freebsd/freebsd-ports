# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	pgpdump
PORTVERSION=	0.32
CATEGORIES=	security
MASTER_SITES=	http://www.mew.org/~kazu/proj/pgpdump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PGP packet visualizer

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pgpdump man/man1/pgpdump.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pgpdump.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
