# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.0.1
CATEGORIES=	print editors
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/ \
		http://scribus.planetmirror.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

.if defined(WITH_GHOSTSCRIPT_AFP1) && ${WITH_GHOSTSCRIPT_AFP1} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	gs:${PORTSDIR}/${GSPORT}

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/scribus/libs \
		%%PREFIX%%/lib/scribus/plugins

QTCFGLIBS+=	-lm

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
