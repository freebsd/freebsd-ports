# New ports collection makefile for:	squirrelmail-change_ldappass-plugin
# Date created:		3 Jul 2005
# Whom:			Alexander Wittig <alexander@wittig.name>
#
# $FreeBSD$

PORTNAME=	change_ldappass
PORTVERSION=	2.2
PORTREVISION=	4
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.4.0
DIST_SUBDIR=	squirrelmail

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Allows users to change their passwords stored in LDAP Tree

LICENSE=	GPLv2

USE_PHP+=	ldap
USE_GETTEXT=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.post.mk>
