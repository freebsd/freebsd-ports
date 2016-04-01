# Created by: dgilbert@velocet.ca
# $FreeBSD$
#    $MCom: ports/print/gutenprint/Makefile,v 1.8 2007/04/03 17:42:21 ahze Exp $

PORTNAME=	gutenprint
PORTVERSION=	5.2.10
CATEGORIES=	print

MAINTAINER=	cmt@burggraben.net
COMMENT=	The "meta-port" for GutenPrint

RUN_DEPENDS=	gutenprint-base>0:print/gutenprint-base

USES=		metaport

OPTIONS_DEFINE=		CUPS GIMP IJS FOOMATIC
OPTIONS_DEFAULT=	IJS
CUPS_DESC=		GutenPrint (gimp-print) Cups Drivers
GIMP_DESC=		GIMP Gutenprint printing plugin
IJS_DESC=		IJS GhostScript Drivers
FOOMATIC_DESC=		Foomatic data files
CUPS_RUN_DEPENDS=	gutenprint-cups>0:print/gutenprint-cups
GIMP_RUN_DEPENDS=	gimp-gutenprint>0:print/gimp-gutenprint
IJS_RUN_DEPENDS=	gutenprint-ijs>0:print/gutenprint-ijs
FOOMATIC_RUN_DEPENDS+=	gutenprint-foomatic>0:print/gutenprint-foomatic

.include <bsd.port.mk>
