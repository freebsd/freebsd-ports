# Created by: HATANO Tomomi <hatanou@infolab.ne.jp>
# $FreeBSD$

PORTNAME=	mkfile
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.infolab.ne.jp/~hatanou/freebsd/mkfile/

MAINTAINER=	hatanou@infolab.ne.jp
COMMENT=	Create files suitable for use as swap files

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

PLIST_FILES=	sbin/mkfile \
		man/man8/mkfile.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkfile ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/mkfile.8.gz ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
