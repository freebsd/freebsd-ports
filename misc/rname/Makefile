PORTNAME=	rname
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://devel.ringlet.net/files/sys/rname/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Execute a program with a fake name
WWW=		https://devel.ringlet.net/sysutils/rname/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_WRKSUBDIR=	yes
USES=		gmake tar:xz uidfix
MAKE_ENV=	BINGRP=wheel \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
PLIST_FILES=	bin/rname share/man/man1/rname.1.gz

.include <bsd.port.mk>
