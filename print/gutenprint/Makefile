# Created by: dgilbert@velocet.ca
# $FreeBSD$
#    $MCom: ports/print/gutenprint/Makefile,v 1.8 2007/04/03 17:42:21 ahze Exp $

PORTNAME=	gutenprint
PORTVERSION=	5.2.8
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	cmt@burggraben.net
COMMENT=	The "meta-port" for GutenPrint

RUN_DEPENDS=	gutenprint-base>0:${PORTSDIR}/print/gutenprint-base

OPTIONS_DEFINE=		CUPS GIMP IJS FOOMATIC
OPTIONS_DEFAULT=	IJS
CUPS_DESC=			GutenPrint (gimp-print) Cups Drivers
GIMP_DESC=			GIMP Gutenprint printing plugin
IJS_DESC=			IJS GhostScript Drivers
FOOMATIC_DESC=		Foomatic data files

NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCUPS}
RUN_DEPENDS+=	gutenprint-cups>0:${PORTSDIR}/print/gutenprint-cups
.endif

.if ${PORT_OPTIONS:MGIMP}
RUN_DEPENDS+=	gimp-gutenprint>0:${PORTSDIR}/print/gimp-gutenprint
.endif

.if ${PORT_OPTIONS:MIJS}
RUN_DEPENDS+=	gutenprint-ijs>0:${PORTSDIR}/print/gutenprint-ijs
.endif

.if ${PORT_OPTIONS:MFOOMATIC}
RUN_DEPENDS+=	gutenprint-foomatic>0:${PORTSDIR}/print/gutenprint-foomatic
.endif

do-install:	# empty

.include <bsd.port.post.mk>
