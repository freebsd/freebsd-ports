# New ports collection makefile for:	twiki-LdapContrib
# Date created:		10 Jun 2008
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	LdapContrib
SVNREV=		16840
PORTREVISION=	1
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	LDAP services for TWiki

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
