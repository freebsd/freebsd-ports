PORTNAME=	arclog
PORTVERSION=	3.04
PORTREVISION=	3
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN/Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Archive the log files monthly

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-TimeDate>=0:devel/p5-TimeDate

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
