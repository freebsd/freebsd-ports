# New ports collection makefile for:	tcltutor
# Date created:		16 November 2000
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	smm++
PORTVERSION=	4r4
CATEGORIES=	net
MASTER_SITES=	http://www.physik.uni-dortmund.de/~issevers/SMM++/downloads/
DISTNAME=	smm

MAINTAINER=	edwin@mavetju.org

RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets3.0.0/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets	\
		${LOCALBASE}/bin/itkwish:${PORTSDIR}/x11-toolkits/itk	\
		${LOCALBASE}/bin/itclsh:${PORTSDIR}/lang/itcl

WRKSRC=		${WRKDIR}/smm4r4
NO_BUILD=	yes

.include <bsd.port.mk>
