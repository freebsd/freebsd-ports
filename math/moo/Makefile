# Created by: Steven Kreuzer <skreuzer@f2o.org>
# $FreeBSD$

PORTNAME=	moo
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	http://www.cyth.net/moo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Calculator that accepts C-like syntax as input

PLIST_FILES=	bin/moo man/man1/moo.1.gz

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/moo.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
