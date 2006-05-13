# New ports collection makefile for:	nv-tv-out
# Date Created:				19 May 2004
# Whom:					Samuel Tardieu <sam@rfc1149.net>
#
# $FreeBSD$
#

PORTNAME=	nvtv
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nv-tv-out
DISTNAME=	nvtv-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TV output on nvidia card

LIB_DEPENDS=	pci.2:${PORTSDIR}/devel/libpci

ONLY_FOR_ARCHS=	i386

CONFIGURE_ENV=	CC="${CC} -I${PREFIX}/include"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gtk12

MAN1=		nvtv.1x
MAN8=		nvtvd.8
PLIST_FILES=	bin/nvtv bin/nvtvd

post-patch:
	@${REINPLACE_CMD} -e 's|-lgnugetopt||g' ${WRKSRC}/configure

.include <bsd.port.mk>
