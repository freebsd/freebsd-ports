# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	splitpatch
PORTVERSION=	1.0.2016122801
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to split a diff patch into separate sections

LICENSE=	GPLv2+

USES=		gmake perl5
USE_PERL5=	build
USE_RUBY=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jaalto
GH_TAGNAME=	13c5941

PLIST_FILES=	bin/splitpatch man/man1/splitpatch.1.gz

MAKE_JOBS_UNSAFE=yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
