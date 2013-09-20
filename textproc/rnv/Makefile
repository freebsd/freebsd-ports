# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	rnv
PORTVERSION=	1.7.11
CATEGORIES=	textproc devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relax NG Compact Syntax validator

LICENSE=	BSD

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-expat="${LOCALBASE}"

MAN1=		rnv.1
PLIST_FILES=	bin/arx bin/rnv bin/rvp bin/xsdck

NO_STAGE=	yes
.include <bsd.port.mk>
