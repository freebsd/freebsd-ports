# New ports collection makefile for: bibletime
# Date created:   3 May 2002
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.6.5
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A powerful Bible study application for KDE3

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.5.10.so:${PORTSDIR}/misc/sword \
		${LOCALBASE}/lib/libclucene.so:${PORTSDIR}/textproc/clucene
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--enable-static-clucene
INSTALLS_ICONS=	yes

DOCSDIR=	share/doc/HTML/en/bibletime

post-patch:
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/bibletime/Makefile.in

.include <bsd.port.mk>
