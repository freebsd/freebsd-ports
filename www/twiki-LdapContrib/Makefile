# New ports collection makefile for:	twiki-LdapContrib
# Date created:		10 Jun 2008
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	LdapContrib
SVNREV=		16840
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	LDAP services for TWiki

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Bundle/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

.include "${.CURDIR}/../twiki/bsd.twiki.mk"
.include <bsd.port.mk>
