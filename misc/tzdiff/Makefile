# Created by: Naito Yuichiro <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	tzdiff
PORTVERSION=	1.0
CATEGORIES=	misc

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Showing time pairs between target timezone and localtime

LICENSE=	BSD2CLAUSE

GH_ACCOUNT=	belgianbeer

USE_GITHUB=	yes

PLIST_FILES=	bin/tzdiff man/man1/tzdiff.1.gz

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tzdiff \
	    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tzdiff.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
