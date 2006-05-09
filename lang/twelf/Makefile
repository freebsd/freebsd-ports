# Ports collection makefile for:	twelf
# Date created:		7/8/5
# Whom:			andrewb@cs.cmu.edu
#
# $FreeBSD$
#

PORTNAME=	twelf
PORTVERSION=	1.4
CATEGORIES=	lang
MASTER_SITES=	http://www-2.cs.cmu.edu/~twelf/dist/ http://www.cs.cmu.edu/~twelf/dist/
DISTNAME=	twelf-1-4

MAINTAINER=	andrewb@cs.cmu.edu
COMMENT=	A meta-logical framework for deductive systems

RUN_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj
BUILD_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj

WRKSRC=		${WRKDIR}/twelf
INFO=		twelf

RESTRICTED=	"License is currently indeterminate (expected to be GPL)"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
