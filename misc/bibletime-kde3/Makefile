# New ports collection makefile for: bibletime
# Date created:   3 May 2002
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.6.5.1
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMESUFFIX=	-kde3

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A powerful Bible study application for KDE3

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.5.11.so:${PORTSDIR}/misc/sword15 \
		${LOCALBASE}/lib/libclucene.so:${PORTSDIR}/textproc/clucene
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFIGURE_ARGS= --with-sword-dir=${LOCALBASE} --with-clucene-dir=${LOCALBASE}

PORTSCOUT=	ignore:1

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CONFIGURE_ARGS+=	--enable-static-clucene
.endif

post-patch:
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/bibletime/Makefile.in

.include <bsd.port.post.mk>
