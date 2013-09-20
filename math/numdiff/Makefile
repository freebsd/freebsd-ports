# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	numdiff
PORTVERSION=	5.6.1
CATEGORIES=	math textproc
MASTER_SITES=	SAVANNAH

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compare putatively similar files, ignoring small numeric differences

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/man \
		--exec-prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} \
		LIBS=-lm \
		--disable-nls
USE_GMAKE=	yes

INFO=	numdiff
MAN1=	ndselect.1 numdiff.1

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--docdir=${WRKDIR}/doc
.endif

.include <bsd.port.mk>
