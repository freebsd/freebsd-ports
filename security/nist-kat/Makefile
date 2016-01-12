# Created by: John-Mark Gurney <jmg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nist-kat
DISTVERSION=	0.0.2015.02.23
CATEGORIES=	security
BASE_URL=	http://csrc.nist.gov/groups/STM/cavp/documents
MASTER_SITES=	${BASE_URL}/aes/:aes
MASTER_SITES+=	${BASE_URL}/des/:des
MASTER_SITES+=	${BASE_URL}/mac/:mac
DISTFILES=	KAT_AES.zip:aes
DISTFILES+=	XTSTestVectors.zip:aes
DISTFILES+=	KAT_TDES.zip:des
DISTFILES+=	gcmtestvectors.zip:mac
DISTFILES+=	hmactestvectors.zip:mac

MAINTAINER=	jmg@FreeBSD.org
COMMENT=	Collection of NIST's Know Answer Test Vectors

LICENSE=        PD

# We want each dist file in it's own subdir
EXTRACT_AFTER_ARGS= -s ":^:nist-kat/$${file%.zip}/:"

NO_BUILD=
NO_WRKSUBDIR=

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share && \
	(cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
