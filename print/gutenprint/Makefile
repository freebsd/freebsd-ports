# ports collection makefile for: gimp-print
# Date Created: 2002 01 02
# Whom: dgilbert@velocet.ca
#
# $FreeBSD$
#    $MCom: ports/print/gutenprint/Makefile,v 1.8 2007/04/03 17:42:21 ahze Exp $
#

PORTNAME=	gutenprint
PORTVERSION=	5.2.7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	cmt@burggraben.net
COMMENT=	The "meta-port" for GutenPrint

RUN_DEPENDS=	gutenprint-base>0:${PORTSDIR}/print/gutenprint-base

OPTIONS=	CUPS "GutenPrint (gimp-print) Cups Drivers" Off \
		IJS "IJS GhostScript Drivers" On \
		FOOMATIC "Foomatic data files" Off

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS)
RUN_DEPENDS+=	gutenprint-cups>0:${PORTSDIR}/print/gutenprint-cups
.endif

.if defined(WITH_GIMP)
RUN_DEPENDS+=	gimp-gutenprint>0:${PORTSDIR}/print/gimp-gutenprint
.endif

.if !defined(WITHOUT_IJS)
RUN_DEPENDS+=	gutenprint-ijs>0:${PORTSDIR}/print/gutenprint-ijs
.endif

.if defined(WITH_FOOMATIC)
RUN_DEPENDS+=	gutenprint-foomatic>0:${PORTSDIR}/print/gutenprint-foomatic
.endif

do-install:	# empty

.include <bsd.port.post.mk>
