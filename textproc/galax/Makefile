# New ports collection makefile for:	galax
# Date created:				17 November 2002
# Whom:					Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	galax
PORTVERSION=	0.3.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://db.bell-labs.com/galax/Downloads/

MAINTAINER=	vs@FreeBSD.org
COMMENT=	Galax is a full-featured, fully compliant implementation of XQuery

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

WRKSRC=		${WRKDIR}/galax

USE_JAVA=	yes
JAVA_VERSION=	1.2+
INSTALLS_SHLIBS=yes
LDCONFIG_DIRS=	${LOCALBASE}/%%GALAX%%/lib/c
USE_GMAKE=	yes
ALL_TARGET=	world
MAKE_ARGS=	JAVAHOME=${JAVA_HOME} JAVAINCLUDE="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd" \
		OCAMLHOME=${LOCALBASE}/lib/ocaml OCAMLBIN=${LOCALBASE}/bin \
		GALAXHOME=${PREFIX}/Galax-${PORTVERSION} APIS="c java" OPTAPIS="c" WITH_CLIBS="-lm -lcurses" \
		CC=${CC} CPP=${CPP}

PLIST_SUB=	GALAX=Galax-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

pre-patch:
	${CP} ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

post-install:
	@${SED} 's,PREFIX,${PREFIX},; s,GALAX,Galax-${PORTVERSION},' ${PKGMESSAGE}

.include <bsd.port.post.mk>
