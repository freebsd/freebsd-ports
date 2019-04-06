# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=		libswift
PORTVERSION=	20160817
PORTREVISION=	2
CATEGORIES=		net-p2p

MAINTAINER=		dch@skunkwerks.at
COMMENT=	IETF Peer-to-Peer Streaming Peer Protocol implementation

LICENSE=	LGPL21

BROKEN_mips=		fails to build: gmake: clang++: Command not found
BROKEN_mips64=		fails to build: gmake: clang++: Command not found
BROKEN_powerpc64=	fails to build: gmake: clang++: Command not found

LIB_DEPENDS=		libevent.so:devel/libevent

USE_GITHUB=		yes
GH_TAGNAME=		dda307f

USES=		gmake ssl

PORTDOCS=		README.md

SUB_FILES=		${PORTNAME}
SUB_LIST+=		SWIFT_USER=${SWIFT_USER} \
			SWIFT_GROUP=${SWIFT_GROUP} \
			SWIFT_SHAREDIR=${SWIFT_SHAREDIR} \
			SWIFT_PIDDIR=${SWIFT_PIDDIR}

PLIST_SUB=		SWIFT_USER=${SWIFT_USER} \
			SWIFT_GROUP=${SWIFT_GROUP} \
			SWIFT_SHAREDIR=${SWIFT_SHAREDIR} \
			SWIFT_PIDDIR=${SWIFT_PIDDIR}

SWIFT_USER?=		www
SWIFT_GROUP?=		www

SWIFT_SHAREDIR=		/var/db/${PORTNAME}/
SWIFT_PIDDIR=		/var/run/${PORTNAME}/

USE_RC_SUBR=		${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	member access into incomplete type 'EVP_PKEY' (aka 'evp_pkey_st')
BROKEN_FreeBSD_13=	member access into incomplete type 'EVP_PKEY' (aka 'evp_pkey_st')
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${SWIFT_SHAREDIR} \
		${STAGEDIR}${SWIFT_PIDDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/swift ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
