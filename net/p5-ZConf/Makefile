# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf
PORTVERSION=	6.1.0
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Configuration system allowing for either file or LDAP backed storage

BUILD_DEPENDS=	p5-Chooser>=0:devel/p5-Chooser \
		p5-Error-Helper>=0:devel/p5-Error-Helper \
		p5-File-BaseDir>=0:devel/p5-File-BaseDir \
		p5-Module-List>=0:devel/p5-Module-List \
		p5-Net-LDAP-AutoDNs>=0:net/p5-Net-LDAP-AutoDNs \
		p5-Net-LDAP-AutoServer>=0:net/p5-Net-LDAP-AutoServer \
		p5-Net-LDAP-LDAPhash>=0:net/p5-Net-LDAP-LDAPhash \
		p5-Net-LDAP-Makepath>=0:net/p5-Net-LDAP-Makepath \
		p5-ZML>=0:devel/p5-ZML \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	bin/zcset bin/zccreate bin/zccdump bin/zcvls \
		bin/zcchooser-set bin/zcget bin/zcchooser-edit \
		bin/zcchooser-get bin/zcchooser-run bin/zcls \
		bin/zcrm bin/zcvdel

.include <bsd.port.mk>
