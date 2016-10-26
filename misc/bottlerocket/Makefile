# Created by: Mike Smith <msmith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bottlerocket
PORTVERSION=	0.04c
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/futurebsd/futurebsd/${PORTNAME}

MAINTAINER=	david@catwhisker.org
COMMENT=	Home Automation Software for the X10 FireCracker kit

USES=		gmake
GNU_CONFIGURE=	yes
ALL_TARGET=	br
PLIST_FILES=	bin/br

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/br ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
