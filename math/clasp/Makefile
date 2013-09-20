# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clasp
PORTVERSION=	2.1.3
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	potassco/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Answer set solver for (extended) normal logic programs

USES=	cmake:outsource

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL} ${INSTALL_WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
