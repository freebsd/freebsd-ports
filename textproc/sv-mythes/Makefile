# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2008.06.10
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sv-
DISTNAME=	thes_sv_SE_v2-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish thesaurus

LICENSE=	MIT

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sv_SE.dat \
		%%DATADIR%%/th_sv_SE.idx \
		%%DATADIR%%/th_sv_FI.dat \
		%%DATADIR%%/th_sv_FI.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sv_SE.dat ${WRKSRC}/th_sv_SE.idx ${STAGEDIR}${DATADIR}/
	${LN} -s th_sv_SE.dat ${STAGEDIR}${DATADIR}/th_sv_FI.dat
	${LN} -s th_sv_SE.idx ${STAGEDIR}${DATADIR}/th_sv_FI.idx

.include <bsd.port.mk>
