# Created by: Ben Kibbey <bjk@arbornet.org>
# $FreeBSD$

PORTNAME=	userinfo
PORTVERSION=	2.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Show information about local users

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		ui.1
MLINKS=		ui.1 userinfo.1

NO_STAGE=	yes
.include <bsd.port.mk>
