# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iriverter
PORTVERSION=	0.16
PORTREVISION=	10
CATEGORIES=	multimedia java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform frontend to mencoder

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt \
		mencoder:multimedia/mencoder

USE_JAVA=	yes
GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2

CONFIGURE_ARGS=	--with-swt="${JAVALIBDIR}/swt.jar"

.include <bsd.port.mk>
