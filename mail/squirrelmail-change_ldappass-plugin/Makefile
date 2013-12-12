# Created by: Alexander Wittig <alexander@wittig.name>
# $FreeBSD$

PORTNAME=		change_ldappass
PORTVERSION=	2.2
PORTREVISION=	5
CATEGORIES=		mail www
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.4.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows users to change their passwords stored in LDAP Tree

LICENSE=	GPLv2

USE_PHP+=	ldap
USES=		gettext

USE_GENERIC_PKGMESSAGE=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
