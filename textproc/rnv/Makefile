# New ports collection makefile for:	rnv
# Date created:	   22 Jan 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	rnv
PORTVERSION=	1.7.10
CATEGORIES=	textproc devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Relax NG Compact Syntax validator

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-expat="${LOCALBASE}"

PLIST_FILES=	bin/arx bin/rnv bin/rvp bin/xsdck

MAN1=		rnv.1

.include <bsd.port.mk>
