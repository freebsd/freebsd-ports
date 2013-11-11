# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Unix-Passwd-File
PORTVERSION=	0.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate passwd and group entries

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Password-Util>=0.06:${PORTSDIR}/security/p5-Crypt-Password-Util \
		p5-File-Flock>=0:${PORTSDIR}/devel/p5-File-Flock \
		p5-Log-Any>=0:${PORTSDIR}/devel/p5-Log-Any
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-chdir>=0:${PORTSDIR}/devel/p5-File-chdir

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
