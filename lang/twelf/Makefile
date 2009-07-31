# Ports collection makefile for:	twelf
# Date created:		7/8/5
# Whom:			andrewb@cs.cmu.edu
#
# $FreeBSD$
#

PORTNAME=	twelf
PORTVERSION=	1.5R1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www-2.cs.cmu.edu/~twelf/dist/ http://www.cs.cmu.edu/~twelf/dist/
DISTNAME=	twelf-1-5R1

MAINTAINER=	andrewb@cs.cmu.edu
COMMENT=	A meta-logical framework for deductive systems

.if defined(WITH_MLTON)
RUN_DEPENDS=	mlton:${PORTSDIR}/lang/mlton
BUILD_DEPENDS=	mlton:${PORTSDIR}/lang/mlton
.elif defined(WITH_SML_NJ_DEVEL)
RUN_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj-devel
BUILD_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj-devel
.else
RUN_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj
BUILD_DEPENDS=	sml:${PORTSDIR}/lang/sml-nj
.endif

BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX

.if defined(WITH_MLTON)
MAKEFILE=	mlton/Makefile
.elif defined(WITH_SML_NJ_DEVEL)
MAKEFILE=	smlnj/Makefile
.endif

WRKSRC=		${WRKDIR}/twelf
INFO=		twelf

RESTRICTED=	License is currently indeterminate (expected to be GPL)

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
