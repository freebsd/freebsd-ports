# Created by: Christopher Boumenot <boumenot@gmail.com>
# $FreeBSD$

PORTNAME=	Sysadm-Install
PORTVERSION=	0.47
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Typical installation tasks for system administrators

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-Expect>=0:lang/p5-Expect \
		p5-File-Which>=1.09:sysutils/p5-File-Which \
		p5-Log-Log4perl>=1.28:devel/p5-Log-Log4perl \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
