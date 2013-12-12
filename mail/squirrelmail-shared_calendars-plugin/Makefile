# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		shared_calendars
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=		mail www
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.4.0

MAINTAINER=		ports@FreeBSD.org
COMMENT=		iCal-compliant calendaring for SquirrelMail

RUN_DEPENDS=	${SQUIRRELDIR}/plugins/calendar_file_backend:${PORTSDIR}/mail/squirrelmail-calendar_file_backend-plugin

USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes
_SMSRCDIR=	calendar

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
