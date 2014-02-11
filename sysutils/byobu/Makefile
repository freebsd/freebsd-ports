# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	3.29
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpadlibrarian.net/65243016/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	gslin@gslin.org
COMMENT=	Profile and configuration utilities for GNU Screen

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/screen:${PORTSDIR}/sysutils/screen

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
		-e "s@/usr/bin/python@${PYTHON_CMD}@" \
		${WRKSRC}/usr/bin/*
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} \
		-e "s@^install:.*@install:@" \
		${WRKSRC}/usr/share/doc/byobu/Makefile.in
.endif

.include <bsd.port.mk>
