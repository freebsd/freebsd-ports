PORTNAME=	POSIX-Run-Capture
PORTVERSION=	1.05
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run command and capture its output
WWW=		https://metacpan.org/dist/POSIX-Run-Capture

LICENSE=	GPLv3+

TEST_DEPENDS=	p5-File-Cmp>=1.06:sysutils/p5-File-Cmp

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/POSIX/Run/Capture/Capture.so

.include <bsd.port.mk>
