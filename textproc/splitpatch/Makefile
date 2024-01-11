PORTNAME=	splitpatch
PORTVERSION=	1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	release/
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to split a diff patch into separate sections
WWW=		https://github.com/jaalto/splitpatch

LICENSE=	GPLv2+

USES=		gmake perl5 ruby
USE_GITHUB=	yes
GH_ACCOUNT=	jaalto
USE_PERL5=	build

MAKE_JOBS_UNSAFE=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/splitpatch \
		share/man/man1/splitpatch.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
