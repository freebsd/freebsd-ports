# Ports collection makefile for:	callgen
# Whom:					Jakub Klausa <jacke@bofh.pl>
# Date created:				January 15 2004
#
# $FreeBSD$

PORTNAME=	callgen323
DISTVERSION=	2.0.0.cvs.20060407
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H.323 Call Generator

USE_GMAKE=	yes
ALL_TARGET=	optshared
MAKE_ENV=	PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OPALDIR=${LOCALBASE}/share/opal \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

PLIST_FILES=	bin/callgen323

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64 && ${OSVERSION} <= 700003
BROKEN=		does not link due to missing symbol in default thread library
.endif

.ifdef (WITH_OPAL)
LIB_DEPENDS+=	opal_r.2:${PORTSDIR}/net/opal
PKGNAMESUFFIX=	-opal
MAKE_ENV+=	USE_OPAL=1
OBJ_DIR=	obj_opal_r
.else
LIB_DEPENDS+=	h323_r.1:${PORTSDIR}/net/openh323
OBJ_DIR=	obj_r
PKGNAMESUFFIX=	-openh323
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OBJ_DIR}/callgen323 ${PREFIX}/bin

.include <bsd.port.post.mk>
