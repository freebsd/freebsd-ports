# New ports collection makefile for: cdbkup
# Date created:				19 May 2003
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	cdbkup
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/release-1-0
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but full-featured backup/restore perl scripts (uses gnu tar)

BUILD_DEPENDS=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject
RUN_DEPENDS=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_CDRTOOLS=	yes
CONFIGURE_ENV+=	PATH=${PATH}:${LOCALBASE}/sbin

MAN1=		cdbkup.1 cdappend.1 cdcat.1 cdrstr.1 cdsplit.1
PORTDOCS=	README TODO COMPLIANCE

.include <bsd.port.mk>
