# New ports collection makefile for:	galax
# Date created:				17 November 2002
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	galax
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://db.bell-labs.com/galax/Downloads/

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	Galax is a full-featured, fully compliant implementation of XQuery

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

WRKSRC=		${WRKDIR}/galax

INSTALLS_SHLIBS=yes
LDCONFIG_DIRS=	${LOCALBASE}/%%GALAX%%/lib/c
USE_GMAKE=	yes
ALL_TARGET=	world
MAKE_ARGS=	JAVAHOME=${JAVA_HOME} OCAMLHOME=${LOCALBASE}/lib/ocaml OCAMLBIN=${LOCALBASE}/bin \
		GALAXHOME=${PREFIX}/Galax-${PORTVERSION} APIS="c" OPTAPIS="c" WITH_CLIBS="-lm -lcurses" \
		CC=${CC} CPP=${CPP}

PLIST_SUB=	GALAX=Galax-${PORTVERSION}

pre-patch:
	${CP} ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

post-install:
	@${SED} 's,PREFIX,${PREFIX},; s,GALAX,Galax-${PORTVERSION},' ${PKGMESSAGE}

.include <bsd.port.mk>
