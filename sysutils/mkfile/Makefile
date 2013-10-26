# Created by: HATANO Tomomi <hatanou@infolab.ne.jp>
# $FreeBSD$

PORTNAME=	mkfile
PORTVERSION=	1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.infolab.ne.jp/~hatanou/freebsd/mkfile/

MAINTAINER=	hatanou@infolab.ne.jp
COMMENT=	Create files suitable for use as swap files

PLIST_FILES=	sbin/mkfile \
		man/man8/mkfile.8.gz

do-install:
	${CP} ${WRKSRC}/mkfile ${STAGEDIR}${PREFIX}/sbin/
	${CP} ${WRKSRC}/mkfile.8.gz ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
