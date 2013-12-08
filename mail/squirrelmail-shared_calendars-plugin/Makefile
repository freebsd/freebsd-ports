# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=		shared_calendars
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=		mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=		${PORTNAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=		ports@FreeBSD.org
COMMENT=		iCal-compliant calendaring for SquirrelMail

USES=		perl5
USE_PERL5=	install
USE_SM_COMPAT=	yes
_SMSRCDIR=	calendar

OPTIONS_DEFINE=	SQL

NO_STAGE=	yes

.include <bsd.port.pre.mk>
.if ${PORT_OPTIONS:MSQL}
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar_sql_backend:${PORTSDIR}/mail/squirrelmail-calendar_sql_backend-plugin
.else
RUN_DEPENDS+=		${SQUIRRELDIR}/plugins/calendar_file_backend:${PORTSDIR}/mail/squirrelmail-calendar_file_backend-plugin
.endif

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
