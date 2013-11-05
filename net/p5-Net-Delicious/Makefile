# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	Net-Delicious
PORTVERSION=	1.1.4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP for managing posts on del.icio.us

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-YAML>=0.35:${PORTSDIR}/textproc/p5-YAML \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Log-Dispatch>=2:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-IO-stringy>=2.1:${PORTSDIR}/devel/p5-IO-stringy \
		p5-TimeDate>=2.27:${PORTSDIR}/devel/p5-TimeDate \
		p5-Config-Simple>=2:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
