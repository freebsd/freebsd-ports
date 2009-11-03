# New ports collection makefile for:	sysutils/p5-Net-LDAP-posixAccount
# Date created:		2009-10-31
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-posixAccount
PORTVERSION=	0.0.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Creates new Net::LDAP::Entry objects for a posixAccount entry

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP/Entry.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Sys/User/UIDhelper.pm:${PORTSDIR}/sysutils/p5-Sys-User-UIDhelper \
		${SITE_PERL}/Sys/Group/GIDhelper.pm:${PORTSDIR}/sysutils/p5-Sys-Group-GIDhelper

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::posixAccount.3

.include <bsd.port.mk>
