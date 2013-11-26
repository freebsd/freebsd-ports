# $FreeBSD$

PORTNAME=	synergy
PORTVERSION=	1.3.8
PORTREVISION=	1
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_XORG=	ice xtst x11 sm

MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include

PLIST_FILES=	bin/synergys bin/synergyc
PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

do-install:
.for f in synergys synergyc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
