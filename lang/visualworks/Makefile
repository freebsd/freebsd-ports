# New ports collection makefile for:	visualworks
# Date created:				17 September 2001
# Whom:					js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	visualworks
PORTVERSION=	7.2
CATEGORIES=	lang linux
MASTER_SITES=	http://www.cincomsmalltalk.com/bsdports/vwnc7.2/
DISTFILES=	AdvancedTools.tar.gz \
		BaseVisualWorks.tar.gz \
		COM.tar.gz \
		DLLC.tar.gz \
		DST.tar.gz \
		Database.tar.gz \
		Goodies.tar.gz \
		GoodiesAragon.tar.gz \
		GoodiesCOAST.tar.gz \
		GoodiesDOME.tar.gz \
		GoodiesJun.tar.gz \
		GoodiesSilverMark.tar.gz \
		I18NCatalogs.tar.gz \
		Opentalk.tar.gz \
		PlugIn.tar.gz \
		Preview.tar.gz \
		Store.tar.gz \
		VM-Linux86.tar.gz \
		WebApplicationServer.tar.gz \
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
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@cd ${WRKDIR} && tar -cf - * | tar -xf - -C ${PREFIX}/${PORTNAME}
	@${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/visual
	@${ECHO_CMD} VISUALWORKS=${PREFIX}/${PORTNAME} >> ${WRKDIR}/visual
	@${ECHO_CMD} export VISUALWORKS >> ${WRKDIR}/visual
	@${ECHO_CMD} ${PREFIX}/${PORTNAME}/bin/linux86/visual $$\* >> ${WRKDIR}/visual
	@${INSTALL_SCRIPT} ${WRKDIR}/visual ${PREFIX}/bin
	@${RM} ${WRKDIR}/visual

post-install:
	@${ECHO_CMD} "      ##########################################################################"
	@${ECHO_CMD} "      To start using VisualWorks, copy the default image to your home directory:"
	@${ECHO_CMD} "        # ${CP} ${PREFIX}/${PORTNAME}/image/visualnc.im ~"
	@${ECHO_CMD} "      Make it writeable:"
	@${ECHO_CMD} "        # ${CHMOD} u+w ~/visualnc.im"
	@${ECHO_CMD} "      Then run it using:"
	@${ECHO_CMD} "        # visual ~/visualnc.im"
	@${ECHO_CMD} "      If this produces an out of memory error message try:"
	@${ECHO_CMD} "        # visual -h 1m ~/visualnc.im"
	@${ECHO_CMD} "      and increase the '1m' value to '2m', ..., until the error goes away."
	@${ECHO_CMD} "      ##########################################################################"

.include <bsd.port.mk>
