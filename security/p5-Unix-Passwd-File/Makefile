# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Unix-Passwd-File
PORTVERSION=	0.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate passwd and group entries

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Password-Util>=0.06:security/p5-Crypt-Password-Util \
		p5-File-Flock-Retry>=0:devel/p5-File-Flock-Retry \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Log-Any-IfLOG>=0:devel/p5-Log-Any-IfLOG
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
