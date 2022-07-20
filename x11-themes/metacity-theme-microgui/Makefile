PORTNAME=	microgui
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/
DISTNAME=	mcitymicrogui-default

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	MicroGUI Sawfish theme for Metacity

LICENSE=	GPLv2

# Converted from RESTRICTED
LICENSE=	metacity
LICENSE_NAME=	metacity
LICENSE_TEXT=	${REASON}
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/microGUI
NO_ARCH=	yes

.include "${.CURDIR}/../metacity-themes/Makefile.metacity"
.include <bsd.port.mk>
