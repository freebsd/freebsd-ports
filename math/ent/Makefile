# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	ent
PORTVERSION=	0.20080128
CATEGORIES=	math
MASTER_SITES=	http://www.fourmilab.ch/random/
DISTNAME=	random
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Entropy calculation and analysis of putative random sequences

USES=		zip
NO_WRKSUBDIR=	yes
ALL_TARGET=	ent
PLIST_FILES=	bin/ent

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

post-patch:
	${REINPLACE_CMD} -e '/CC = /d' -e '/CFLAGS = /s,$$, ${CFLAGS},' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
