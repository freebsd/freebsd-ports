# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfs3
PORTVERSION=	0.9.22
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A user-space implementation of the NFSv3 server specification

USE_AUTOTOOLS=	autoconf
USES=		bison

MAN7=		tags.7
MAN8=		unfsd.8
PLIST_FILES=	sbin/unfsd

MAKE_JOBS_UNSAFE=	yes

.if defined(WITH_CLUSTER_EXT)
CONFIGURE_ARGS+=	--enable-cluster
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
