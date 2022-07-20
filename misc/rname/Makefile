PORTNAME=	rname
PORTVERSION=	1.0.2
CATEGORIES=	misc
MASTER_SITES=	http://devel.ringlet.net/files/sys/rname/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Execute a program with a fake name

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_WRKSUBDIR=	yes
USES=		gmake tar:xz uidfix
MAKE_ENV=	BINGRP=wheel MANDIR=${PREFIX}/man \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
PLIST_FILES=	bin/rname man/man1/rname.1.gz

.include <bsd.port.mk>
