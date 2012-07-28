# New ports collection makefile for:	squirrelmail-postfixadmin-plugin
# Date created:		2010-01-31
# Whom:			Darren Pilgrim <ports.maintainer@evilphi.com>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	http://vivi.cat.pdx.edu/sm-pfa-plugin/
PKGNAMEPREFIX=	squirrelmail-
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	squirrelmail

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Lets users change password, vacation, and forwarding

RUN_DEPENDS=	ZendFramework>=1.9.0:${PORTSDIR}/www/zend-framework

USE_BZIP2=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"

pre-install:
	${RM} -rf ${WRKSRC}/${_SMSRCDIR}/debian

.include <bsd.port.post.mk>
