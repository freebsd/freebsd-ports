# New ports collection makefile for:	galax
# Date created:				17 November 2002
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	galax
PORTVERSION=	0.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://db.bell-labs.com/galax/Downloads/

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

WRKSRC=		${WRKDIR}/galax

USE_GMAKE=	yes
ALL_TARGET=	world
MAKE_ENV=	PREFIX=${PREFIX} JAVA_HOME=${JAVE_HOME}

PLIST_SUB=	GALAX=Galax-${PORTVERSION}

pre-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/config

post-install:
	@${SED} 's,PREFIX,${PREFIX},; s,GALAX,Galax-${PORTVERSION},' ${PKGMESSAGE}

.include <bsd.port.mk>
