# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	MIME_Type
PORTVERSION=	1.3.4
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class for dealing with MIME types

OPTIONS_DEFINE=	PEAR_SYSTEM_COMMAND
PEAR_SYSTEM_COMMAND_DESC=	PEAR::System_Command support

USES=	pear

PEAR_SYSTEM_COMMAND_RUN_DEPENDS=	${PEARDIR}/System/Command.php:${PORTSDIR}/devel/pear-System_Command

.include <bsd.port.mk>
