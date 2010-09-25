# New ports collection makefile for:	sysutils/p5-Plugtools
# Date created:		2009-10-31
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Plugtools
PORTVERSION=	1.3.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Manages POSIX users in LDAP and is extensible via a plugin system

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP/Entry.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Sys/User/UIDhelper.pm:${PORTSDIR}/sysutils/p5-Sys-User-UIDhelper \
		${SITE_PERL}/Sys/Group/GIDhelper.pm:${PORTSDIR}/sysutils/p5-Sys-Group-GIDhelper \
		${SITE_PERL}/Net/LDAP/posixAccount.pm:${PORTSDIR}/net/p5-Net-LDAP-posixAccount \
		${SITE_PERL}/Net/LDAP/posixGroup.pm:${PORTSDIR}/net/p5-Net-LDAP-posixGroup \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote \
		${SITE_PERL}/File/BaseDir.pm:${PORTSDIR}/devel/p5-File-BaseDir \
		${SITE_PERL}/Config/IniHash.pm:${PORTSDIR}/devel/p5-Config-IniHash

PERL_CONFIGURE=	yes

MAN3=		Plugtools.3 \
		Plugtools::Plugins::Dump.3

.include <bsd.port.mk>
