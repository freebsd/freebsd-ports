# Created by: Christopher Boumenot <boumenot@gmail.com>
# $FreeBSD$
#

PORTNAME=	Sysadm-Install
PORTVERSION=	0.42
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Typical installation tasks for system administrators

BUILD_DEPENDS=	p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Expect>=0:${PORTSDIR}/lang/p5-Expect \
		p5-Log-Log4perl>=1.28:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Sysadm::Install.3

.include <bsd.port.mk>
