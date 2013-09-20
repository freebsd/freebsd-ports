# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rats
PORTVERSION=	2.3
CATEGORIES=	security devel
MASTER_SITES=	https://www.fortify.com/downloads2/public/ \
				http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Source code auditing tool

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-expat-lib=${LOCALBASE}/lib \
		--with-expat-include=${LOCALBASE}/include/xml \
		--datadir=${DATADIR}

ALL_TARGET=	${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
MAN1=		rats.1

.include <bsd.port.mk>
