# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	microgui
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
DISTNAME=	mcitymicrogui-default

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	The microGUI Sawfish theme for Metacity

LICENSE=	GPLv2

USE_GNOME=	gnomehier

RESTRICTED=	${REASON}

WRKSRC=		${WRKDIR}/microGUI

.include "${.CURDIR}/../metacity-themes/Makefile.metacity"
.include <bsd.port.mk>
