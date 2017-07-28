# Created by: Steven Kreuzer <skreuzer@f2o.org>
# $FreeBSD$

PORTNAME=	moo
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Calculator that accepts C-like syntax as input

LICENSE=	PD

USE_GITHUB=	yes
GH_ACCOUNT=	raylai

PLIST_FILES=	bin/moo man/man1/moo.1.gz

.if exists(/usr/include/sys/capsicum.h) && exists(/usr/include/capsicum_helpers.h)
CFLAGS+=	-DHAVE_CAPSICUM
.endif

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/moo.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
