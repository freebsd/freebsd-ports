# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	LdapContrib
SVNREV=		16840
PORTREVISION=	1
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

COMMENT=	LDAP services for TWiki

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

NO_STAGE=	yes
.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
