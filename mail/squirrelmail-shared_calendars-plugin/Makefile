# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	shared_calendars
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	mail www
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.4.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	iCal-compliant calendaring for SquirrelMail

RUN_DEPENDS=	squirrelmail-calendar_file_backend-plugin${PHP_PKGNAMESUFFIX}>0:mail/squirrelmail-calendar_file_backend-plugin@${PHP_FLAVOR}

USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes
_SMSRCDIR=	calendar

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
