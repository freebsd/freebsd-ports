# Created by: Neil Darlow <neil@darlow.co.uk>
# $FreeBSD$

PORTNAME=	password_forget
PORTVERSION=	2.2
CATEGORIES=	mail www
MASTER_SITES=	http://www.squirrelmail.org/plugins/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${SQUIRREL_PLUGIN_NAME}-${PORTVERSION}-1.0.1
DIST_SUBDIR=	squirrelmail

MAINTAINER=	neil@darlow.co.uk
COMMENT=	Prevent reuse of login details by browsers at public terminals

RUN_DEPENDS=	${SQUIRRELDIR}/plugins/compatibility:${PORTSDIR}/mail/squirrelmail-compatibility-plugin

USE_PERL5_RUN=	yes

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
