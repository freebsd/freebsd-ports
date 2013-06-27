# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		calendar_sql_backend
PORTVERSION=	1.1
PORTREVISION=	1
DISTNAME=		${PORTNAME}-${PORTVERSION}-2.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=		ports@FreeBSD.org
COMMENT=		SQL backend for SquirrelMail Calendar plugin

BROKEN=			does not build

RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
PEARDIR=		${PREFIX}/share/pear

SQUIRREL_PLUGIN_NAME=	${PORTNAME}

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
