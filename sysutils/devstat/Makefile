# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	devstat
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Utility to display device statistics

PLIST_FILES=	bin/devstat
MAN8=		devstat.8

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/devstat ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/devstat.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
