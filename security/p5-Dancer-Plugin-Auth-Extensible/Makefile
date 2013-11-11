# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Auth-Extensible
PORTVERSION=	0.30
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Extensible authentication framework for Dancer apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SaltedHash>=0:${PORTSDIR}/security/p5-Crypt-SaltedHash \
		p5-Dancer>=1.3118:${PORTSDIR}/www/p5-Dancer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DPAEPD DPAEPU
DPAEPD_DESC=	Extra dependencies for Provider::Database
DPAEPU_DESC=	Extra dependencies for Provider::Unix

DPAEPD_BUILD_DEPENDS=	p5-Dancer-Plugin-Database>=0:${PORTSDIR}/databases/p5-Dancer-Plugin-Database
DPAEPU_BUILD_DEPENDS=	p5-Authen-Simple-PAM>=0:${PORTSDIR}/security/p5-Authen-Simple-PAM \
			p5-Unix-Passwd-File>=0:${PORTSDIR}/security/p5-Unix-Passwd-File

.include <bsd.port.mk>
