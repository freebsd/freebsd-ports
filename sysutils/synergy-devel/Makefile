# Created by: George Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synergy
PORTVERSION=	1.4.12
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-devel

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

EXTRACT_DEPENDS= unzip:${PORTSDIR}/archivers/unzip

CONFLICTS=	synergy-[0-9]*
USES=		cmake
USE_XORG=	ice xtst x11 sm
USE_DOS2UNIX=	yes

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include

PLIST_FILES=	bin/synergys bin/synergyc
PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

NO_STAGE=	yes
post-extract:
	cd ${WRKSRC}/tools/
	${MKDIR} ${WRKSRC}/tools/cryptopp562
	(cd ${WRKSRC}/tools/cryptopp562 && unzip ${WRKSRC}/tools/cryptopp562.zip)

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
