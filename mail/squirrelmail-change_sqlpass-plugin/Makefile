# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	change-sqlpass
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=		mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.2

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Allows users to change their passwords stored in a SQL database

USE_SM_COMPAT=	yes

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
