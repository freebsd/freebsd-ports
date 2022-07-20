PORTNAME=	Proc-ProcessTable-ncps
PORTVERSION=	0.1.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Searches the process table and displays the results

LICENSE=	ART20

BUILD_DEPENDS=	p5-Data-Unixish>=1.57:devel/p5-Data-Unixish \
		p5-Proc-ProcessTable-InfoString>0:sysutils/p5-Proc-ProcessTable-InfoString \
		p5-Proc-ProcessTable-Match>0:sysutils/p5-Proc-ProcessTable-Match \
		p5-Proc-ProcessTable>=0.59:devel/p5-Proc-ProcessTable \
		p5-Statistics-Basic>=1.6611:math/p5-Statistics-Basic \
		p5-Term-ANSIColor>0:devel/p5-Term-ANSIColor \
		p5-Text-ANSITable>=0.501:textproc/p5-Text-ANSITable
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/ncps \
		${SITE_MAN3_REL}/Proc::ProcessTable::ncps.3.gz \
		${SITE_PERL_REL}/Proc/ProcessTable/ncps.pm

.include <bsd.port.mk>
