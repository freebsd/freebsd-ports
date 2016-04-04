# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Plugtools
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Manages POSIX users in LDAP and is extensible via a plugin system

RUN_DEPENDS=	p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Sys-User-UIDhelper>=0:sysutils/p5-Sys-User-UIDhelper \
		p5-Sys-Group-GIDhelper>=0:sysutils/p5-Sys-Group-GIDhelper \
		p5-Net-LDAP-posixAccount>=0:net/p5-Net-LDAP-posixAccount \
		p5-Net-LDAP-posixGroup>=0:net/p5-Net-LDAP-posixGroup \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote \
		p5-File-BaseDir>=0:devel/p5-File-BaseDir \
		p5-Config-IniHash>=0:devel/p5-Config-IniHash

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/*
USE_PERL5=	configure

.include <bsd.port.mk>
