# New ports collection makefile for:	galax
# Date created:				17 November 2002
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	galax
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://db.bell-labs.com/galax/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Galax is a full-featured, fully compliant implementation of XQuery

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

WRKSRC=		${WRKDIR}/galax

USE_JAVA=	yes
JAVA_VERSION=	1.3 1.4
USE_GMAKE=	yes
ALL_TARGET=	world
MAKE_ARGS=	JAVAHOME=${JAVA_HOME} JAVAINCLUDE="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd" \
		OCAMLHOME=${LOCALBASE}/lib/ocaml OCAMLBIN=${LOCALBASE}/bin \
		GALAXHOME=${PREFIX}/Galax-${PORTVERSION} APIS="c java" OPTAPIS="c" WITH_CLIBS="-lm -lcurses" \
		CC=${CC} CPP=${CPP}

PLIST_SUB+=	GALAX=Galax-${PORTVERSION}
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON= Java-1.4 is only available for i386

.include <bsd.port.pre.mk>

pre-patch:
	${CP} ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

post-install:
	@${SED} 's,PREFIX,${PREFIX},; s,GALAX,Galax-${PORTVERSION},' ${PKGMESSAGE}

.include <bsd.port.post.mk>
