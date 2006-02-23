# New ports collection makefile for:	fakeroot
# Date created:				11 March 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	fakeroot
PORTVERSION=	1.5.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/f/fakeroot
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	Meno.Abels@Adviser.com
COMMENT=	Simulate the root user behaviour

BUILD_DEPENDS=	${LOCALBASE}/bin/po4a:${PORTSDIR}/textproc/po4a

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MANLANG=	"" es sv fr
MAN1=		faked.1 fakeroot.1

.include <bsd.port.mk>
