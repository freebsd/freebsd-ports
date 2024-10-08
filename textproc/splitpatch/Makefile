PORTNAME=	splitpatch
DISTVERSIONPREFIX=	release/
DISTVERSION=	1.2
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to split a diff patch into separate sections
WWW=		https://github.com/jaalto/splitpatch

LICENSE=	GPLv2+

USES=		gmake perl5 ruby
USE_GITHUB=	yes
GH_ACCOUNT=	jaalto
USE_PERL5=	build

NO_ARCH=	yes

PLIST_FILES=	bin/splitpatch \
		share/man/man1/splitpatch.1.gz

.include <bsd.port.mk>
