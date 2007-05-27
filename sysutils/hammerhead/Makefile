# New ports collection makefile for:   hammerhead
# Date created:        14 November 2002
# Whom:                John von Essen
#
# $FreeBSD$
#

PORTNAME=	hammerhead
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A webserver stressing tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/src/Makefile

MAN1=	hammerhead.1

.include <bsd.port.post.mk>
