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
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Creates new Net::LDAP::Entry objects for a posixAccount entry

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Sys-User-UIDhelper>=0:${PORTSDIR}/sysutils/p5-Sys-User-UIDhelper \
		p5-Sys-Group-GIDhelper>=0:${PORTSDIR}/sysutils/p5-Sys-Group-GIDhelper

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::LDAP::posixAccount.3

.include <bsd.port.mk>
