# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.0
CATEGORIES=	print editors
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/ \
		http://scribus.planetmirror.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/scribus/libs \
		%%PREFIX%%/lib/scribus/plugins

QTCFGLIBS+=	-lm

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
