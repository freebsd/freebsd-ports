# New ports collection makefile for:	tcltutor
# Date created:		16 November 2000
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	smm++
PORTVERSION=	5r0
CATEGORIES=	net
MASTER_SITES=	http://www.issever.de/smm/downloads/
DISTNAME=	smm

MAINTAINER=	edwin@mavetju.org

RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets3.0.0/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets	\
		${LOCALBASE}/bin/itkwish:${PORTSDIR}/x11-toolkits/itk	\
		${LOCALBASE}/bin/itclsh:${PORTSDIR}/lang/itcl

WRKSRC=		${WRKDIR}/smm5r0/Install.unix
USE_GMAKE=	yes

do-configure:
	@echo "No configure needed"

.include <bsd.port.mk>
