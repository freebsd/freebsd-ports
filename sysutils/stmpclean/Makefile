# Created by: shalunov
# $FreeBSD$

PORTNAME=	stmpclean
PORTVERSION=	0.3
CATEGORIES=	sysutils security
MASTER_SITES=	http://shlang.com/stmpclean/

MAINTAINER=	shalunov@shlang.com
COMMENT=	Remove old files from temporary directories

MAN8=		stmpclean.8
MANCOMPRESSED=	no
PLIST_FILES=	sbin/stmpclean

post-patch:
	@${REINPLACE_CMD} -e "s/-O6//g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
