# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	devstat
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Utility to display device statistics

BROKEN=		Unfetchable (google code has gone away)

PLIST_FILES=	bin/devstat \
		man/man8/devstat.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/devstat ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/devstat.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
