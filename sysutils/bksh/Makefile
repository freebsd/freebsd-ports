# Created by: The Anarcat <anarcat@anarcat.ath.cx>
# $FreeBSD$

PORTNAME=	bksh
PORTVERSION=	1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://anarcat.ath.cx/software/distfiles/

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	Backup-only shell

USES=		uidfix

PLIST_FILES=	bin/bksh

post-patch:
	@${REINPLACE_CMD} -e "s/NOMAN.*/MAN=/" ${WRKSRC}/local.mk

.include <bsd.port.mk>
