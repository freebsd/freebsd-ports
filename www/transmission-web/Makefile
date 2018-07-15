# $FreeBSD$

CATEGORIES=	www
PKGNAMESUFFIX=	-web

USES=		cpe
NO_ARCH=	yes
NO_BUILD=	yes
PORTDATA=	web

MASTERDIR=	${.CURDIR}/../../net-p2p/transmission-cli
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${NONEXISTENT}

SLAVEPORT=	web

#post-extract:
#	@${FIND} ${WRKSRC}/web \( -name '*.am' -o -name '*.in' \
		-o -name '*.scss' \) -delete

#do-install:
#	( cd ${WRKSRC} && ${COPYTREE_SHARE} web ${STAGEDIR}${DATADIR} )

.include "${MASTERDIR}/Makefile"
