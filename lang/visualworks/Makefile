# New ports collection makefile for:	visualworks
# Date created:				17 September 2001
# Whom:					js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	visualworks
PORTVERSION=	5i.4
CATEGORIES=	lang linux
MASTER_SITES=	ftp://ftp.cincom.com/pub/st/vw/ \
		ftp://ftp.cincom.com/pub/st/vm/ \
		ftp://ftp.cincom.com/pub/st/goodies/
DISTFILES=	BaseVisualWorks.tar.gz Image.tar.gz VM-Linux86.tar.gz \
		ExtendedBase.tar.gz DST.tar.gz PlugIn.tar.gz \
		VisualWaveWebToolkit.tar.gz Opentalk.tar.gz \
		I18NCatalogs.tar.gz Goodies.tar.gz Goodies-Aragon.tar.gz \
		Goodies-DOME.tar.gz Goodies-Jun.tar.gz
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	js@jeannot.org

USE_LINUX=	yes

ONLY_FOR_ARCHS= i386

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RESTRICTED=	"Redistribution is probably not permitted."

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}/${PORTVERSION}
	@cd ${WRKDIR} && tar -cf - * | tar -xf - -C ${PREFIX}/${PORTNAME}/${PORTVERSION}
	@echo "#!/bin/sh" > ${PREFIX}/bin/visual
	@echo VISUALWORKS=${PREFIX}/${PORTNAME}/${PORTVERSION} >> ${PREFIX}/bin/visual
	@echo export VISUALWORKS >> ${PREFIX}/bin/visual
	@echo ${PREFIX}/${PORTNAME}/${PORTVERSION}/bin/linux86/visual $$\* >> ${PREFIX}/bin/visual
	@${CHMOD} a+x ${PREFIX}/bin/visual

post-install:
	@echo To start using VisualWorks,
	@echo First copy the default image to your home directory :
	@echo ${CP} ${PREFIX}/${PORTNAME}/${PORTVERSION}/image/visualnc.im ~
	@echo Make it writeable:
	@echo ${CHMOD} u+w ~/visualnc.im
	@echo Then run it using:
	@echo visual ~/visualnc.im

.include <bsd.port.mk>
