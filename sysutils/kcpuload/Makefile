# New ports collection makefile for:	KCPUload
# Date Created:				10 Jan, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kcpuload
PORTVERSION=	1.99
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://ftp.kde.com/Administration/Monitoring/Resources/KCPULoad/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	CPU meter for Kicker

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="-e s,x,x,"

# Hmm, I don't know how to tell meinproc where it should search for DTDs...
post-patch:
	@${LN} -s ${PREFIX}/share/apps/ksgmltools2/customization/dtd ${WRKSRC}/doc/en/dtd

.include <bsd.port.mk>
