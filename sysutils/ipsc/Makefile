# New ports collection makefile for:	ipsc
# Date created:		31 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	ipsc
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://ipsc.sourceforge.net/dist/ipsc/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jeremy@external.org
COMMENT=	An IP Subnet Calculator

BUILD_DEPENDS=	${PORTSDIR}/sysutils/prips/work/prips/prips.o:${PORTSDIR}/sysutils/prips:build

WRKSRC=		${WRKDIR}/ipsc/src

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_X_PREFIX=	yes
USE_GNOME=	yes
ALL_TARGET=	all
.else
ALL_TARGET=	ipsc
.endif

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

post-extract:
	@${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../prips/work/prips \
		${WRKDIR}/prips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${PREFIX}/bin
.if defined(HAVE_GNOME)
	${INSTALL_PROGRAM} ${WRKSRC}/gipsc ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
