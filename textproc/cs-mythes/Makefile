# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2007.09.26
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	cs-
DISTNAME=	thes_cs_CZ_v2-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech thesaurus

LICENSE=	BSD

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_cs_CZ_v2.dat \
		%%DATADIR%%/th_cs_CZ_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_cs_CZ_v2.dat ${WRKSRC}/th_cs_CZ_v2.idx ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
