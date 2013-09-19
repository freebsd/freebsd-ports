# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	login_notes
PORTVERSION=	1.2
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Place notes on the login screen

LICENSE=	GPLv2

RUN_DEPENDS+=	${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

USES=		perl5
USE_PERL5=	run

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
