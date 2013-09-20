# Created by: ijliao
# $FreeBSD$

PORTNAME=	gexpr
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/math/calc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A shell calculator

MAN1=		gexpr.1
PLIST_FILES=	bin/gexpr

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
