# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2015.10.11
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	nl-
DISTNAME=	thes_nl-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch thesaurus

LICENSE=	BSD3CLAUSE

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_nl_NL_v2.dat \
		%%DATADIR%%/th_nl_NL_v2.idx

NLALIASES=	nl_AW nl_BE
.for ALIAS in ${NLALIASES}
PLIST_FILES+=	%%DATADIR%%/th_${ALIAS}_v2.dat \
		%%DATADIR%%/th_${ALIAS}_v2.idx
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_nl_v2.dat ${STAGEDIR}${DATADIR}/th_nl_NL_v2.dat
	${INSTALL_DATA} ${WRKSRC}/th_nl_v2.dat ${STAGEDIR}${DATADIR}/th_nl_NL_v2.idx
.for ALIAS in ${NLALIASES}
	${LN} -s th_nl_NL_v2.dat ${STAGEDIR}${DATADIR}/th_${ALIAS}_v2.dat
	${LN} -s th_nl_NL_v2.idx ${STAGEDIR}${DATADIR}/th_${ALIAS}_v2.idx
.endfor

.include <bsd.port.mk>
