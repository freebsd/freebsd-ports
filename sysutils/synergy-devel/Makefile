# New ports collection makefile for:	synergy-devel
# Date created:		6 February 2012
# Whom:			George Neville-Neil <gnn@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	synergy
PORTVERSION=	1.4.7
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=  -devel

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

CONFLICTS=	synergy-[0-9]*
USE_CMAKE=	yes
USE_XORG=	ice xtst x11 sm
MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include

PLIST_FILES=	bin/synergys bin/synergyc
PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

do-install:
.for f in synergys synergyc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
