# Created by: Darren Pilgrim <ports.maintainer@evilphi.com>
# $FreeBSD$

PORTNAME=	postfixadmin
PORTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	http://a.aranea.brtsvcs.net/sm-pfa-plugin/ \
		http://b.aranea.brtsvcs.net/sm-pfa-plugin/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Lets users change password, vacation, and forwarding

RUN_DEPENDS=	ZendFramework>=1.9.0:${PORTSDIR}/www/zend-framework1

USE_BZIP2=	yes
DEFAULT_PHP_VER=	53

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"

pre-install:
	${RM} -rf ${WRKSRC}/${_SMSRCDIR}/debian

.include <bsd.port.mk>
