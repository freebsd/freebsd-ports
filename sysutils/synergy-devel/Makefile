# Created by: George Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synergy
PORTVERSION=	1.4.15
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-devel

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2

CONFLICTS=	synergy-[0-9]*
USES=		cmake
USE_XORG=	ice xtst x11 sm
USE_DOS2UNIX=	yes

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include

PLIST_FILES=	bin/synergys bin/synergyc
PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

post-extract:
	cd ${WRKSRC}/tools/
	${MKDIR} ${WRKSRC}/tools/cryptopp562
	(cd ${WRKSRC}/tools/cryptopp562 && ${TAR} xfz ${WRKSRC}/tools/cryptopp562.zip)

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
