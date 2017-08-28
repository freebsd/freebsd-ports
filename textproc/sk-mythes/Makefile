# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2017.08.27
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sk-
DISTNAME=	OOo-Thesaurus2-sk_SK-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak thesaurus

LICENSE=	MIT

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sk_SK_v2.dat \
		%%DATADIR%%/th_sk_SK_v2.idx

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sk_SK_v2.dat ${WRKSRC}/th_sk_SK_v2.idx ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
