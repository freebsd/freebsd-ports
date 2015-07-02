# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Unix-Passwd-File
PORTVERSION=	0.20
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate passwd and group entries

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Password-Util>=0.06:${PORTSDIR}/security/p5-Crypt-Password-Util \
		p5-File-Flock>=0:${PORTSDIR}/devel/p5-File-Flock \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Log-Any-IfLOG>=0:${PORTSDIR}/devel/p5-Log-Any-IfLOG \
		p5-Rinci>=1.1.76:${PORTSDIR}/devel/p5-Rinci
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Slurp-Tiny>=0:${PORTSDIR}/devel/p5-File-Slurp-Tiny \
		p5-File-chdir>=0:${PORTSDIR}/devel/p5-File-chdir \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-experimental>=0:${PORTSDIR}/devel/p5-experimental
RUN_DEPENDS+=	p5-experimental>=0:${PORTSDIR}/devel/p5-experimental
.endif

.include <bsd.port.post.mk>
