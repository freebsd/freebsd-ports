# New ports collection makefile for:	p5-Net-LDAP-Makepath
# Date created:		2008-06-24
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf
PORTVERSION=	1.2.0
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A configuration system allowing for either file or LDAP backed storage

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP/Entry.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Net/LDAP/Express.pm:${PORTSDIR}/net/p5-Net-LDAP-Express \
		${SITE_PERL}/Net/LDAP/LDAPhash.pm:${PORTSDIR}/net/p5-Net-LDAP-LDAPhash \
		${SITE_PERL}/Net/LDAP/Makepath.pm:${PORTSDIR}/net/p5-Net-LDAP-Makepath \
		${SITE_PERL}/ZML.pm:${PORTSDIR}/devel/p5-ZML \
		${SITE_PERL}/Chooser.pm:${PORTSDIR}/devel/p5-Chooser \
		${SITE_PERL}/File/BaseDir.pm:${PORTSDIR}/devel/p5-File-BaseDir

PERL_CONFIGURE=	yes

MAN3=		ZConf.3

.include <bsd.port.mk>
