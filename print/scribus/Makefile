# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/ \
		http://scribus.planetmirror.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive desktop publishing program

USE_GHOSTSCRIPT_RUN=	yes

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/scribus/libs \
		%%PREFIX%%/lib/scribus/plugins

QTCFGLIBS+=	-lm

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
