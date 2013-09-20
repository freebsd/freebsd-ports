# Created by: Craig Boston <craig@yekse.gank.org>
# $FreeBSD$

PORTNAME=	vde
PORTVERSION=	1.5.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

CONFLICTS=	vde2-[0-9]*

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

NO_STAGE=	yes
.include <bsd.port.pre.mk>

CFLAGS+=	${CPPFLAGS} -fPIC

MAN1=		dpipe.1 slirpvde.1 vdetaplib.1 vdeq.1 vde_plug.1 vde_switch.1

.include <bsd.port.post.mk>
