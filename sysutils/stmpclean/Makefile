# Created by: shalunov
# $FreeBSD$

PORTNAME=	stmpclean
PORTVERSION=	0.3
CATEGORIES=	sysutils security
MASTER_SITES=	http://shlang.com/stmpclean/

MAINTAINER=	shalunov@shlang.com
COMMENT=	Remove old files from temporary directories

BROKEN=		unfetchable

USES=		groff
PLIST_FILES=	sbin/stmpclean man/man8/stmpclean.8.gz

post-patch:
	@${REINPLACE_CMD} -e "s/-O6//g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
