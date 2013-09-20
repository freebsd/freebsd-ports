# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	cdbkup
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/release-1-0
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but full-featured backup/restore perl scripts (uses gnu tar)

BUILD_DEPENDS=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject \
		cdrecord:${PORTSDIR}/sysutils/cdrtools
RUN_DEPENDS=	${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		perl5
CONFIGURE_ENV+=	PATH=${PATH}:${LOCALBASE}/sbin

MAN1=		cdbkup.1 cdappend.1 cdcat.1 cdrstr.1 cdsplit.1
PORTDOCS=	README TODO COMPLIANCE

NO_STAGE=	yes
.include <bsd.port.mk>
