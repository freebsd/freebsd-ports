# New ports collection makefile for:	visualworks
# Date created:				17 September 2001
# Whom:					js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	visualworks
PORTVERSION=	7.1
CATEGORIES=	lang linux
MASTER_SITES=	http://www.cincomsmalltalk.com/bsdports/vwnc7.1/
DISTFILES=	BaseVisualWorks.tar.gz \
		COM.tar.gz \
		DST.tar.gz \
		ExtendedBase.tar.gz \
		Goodies-Aragon.tar.gz \
		Goodies-DOME.tar.gz \
		Goodies-Jun.tar.gz \
		Goodies.tar.gz \
		I18NCatalogs.tar.gz \
		Image.tar.gz \
		Opentalk.tar.gz \
		PlugIn.tar.gz \
		Preview.tar.gz \
		VM-Linux86.tar.gz \
		VisualWaveWebToolkit.tar.gz \
		WebServices.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	chris@chrisburkert.de
COMMENT=	A high performance Smalltalk environment

USE_LINUX=	yes

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_PACKAGE=	yes
NO_CDROM=	yes

RESTRICTED=	"Redistribution is probably not permitted."

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}/${PORTVERSION}
	@cd ${WRKDIR} && tar -cf - * | tar -xf - -C ${PREFIX}/${PORTNAME}/${PORTVERSION}
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/visual
	@${ECHO_CMD} VISUALWORKS=${PREFIX}/${PORTNAME}/${PORTVERSION} >> ${WRKDIR}/visual
	@${ECHO_CMD} export VISUALWORKS >> ${WRKDIR}/visual
	@${ECHO_CMD} ${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/linux86/visual $$\* >> ${WRKDIR}/visual
	@${INSTALL_SCRIPT} ${WRKDIR}/visual ${PREFIX}/bin
	@${RM} ${WRKDIR}/visual

post-install:
	@${ECHO_CMD} "   To start using VisualWorks,"
	@${ECHO_CMD} "   First copy the default image to your home directory :"
	@${ECHO_CMD} "   ${CP} ${PREFIX}/${PORTNAME}/${PORTVERSION}/image/visualnc.im ~"
	@${ECHO_CMD} "   Make it writeable:"
	@${ECHO_CMD} "   ${CHMOD} u+w ~/visualnc.im"
	@${ECHO_CMD} "   Then run it using:"
	@${ECHO_CMD} "   visual ~/visualnc.im"
	@${ECHO_CMD} "   If this produces an out of memory error message try:"
	@${ECHO_CMD} "   visual -h 1m ~/visualnc.im"
	@${ECHO_CMD} "   and increase the '1m' value to '2m', ..., until the error goes away."

.include <bsd.port.mk>
