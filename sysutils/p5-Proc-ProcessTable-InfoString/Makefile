# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Proc-ProcessTable-InfoString
PORTVERSION=	0.0.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Creates a PS like stat string showing the flags/state/wchan

BUILD_DEPENDS=	p5-Proc-ProcessTable>=0.59:devel/p5-Proc-ProcessTable \
		p5-Term-ANSIColor>0:devel/p5-Term-ANSIColor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_MAN3_REL}/Proc::ProcessTable::InfoString.3.gz \
		${SITE_PERL_REL}/Proc/ProcessTable/InfoString.pm

.include <bsd.port.mk>
