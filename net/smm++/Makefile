# New ports collection makefile for:	tcltutor
# Date created:		16 November 2000
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	smm++
PORTVERSION=	5.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	smm
DISTNAME=	smm

MAINTAINER=	edwin@mavetju.org

RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets3.0.0/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets	\
		${LOCALBASE}/lib/libitk32.so:${PORTSDIR}/x11-toolkits/itk      \
		${LOCALBASE}/lib/libitcl32.so:${PORTSDIR}/lang/itcl

WRKSRC=		${WRKDIR}/smm/Install.unix
USE_GMAKE=	yes

do-configure:
	@echo "No configure needed"

.include <bsd.port.mk>
