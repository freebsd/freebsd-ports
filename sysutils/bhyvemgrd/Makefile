PORTNAME=	bhyvemgrd
DISTVERSIONPREFIX=	v
PORTVERSION=	1.1.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	privileged helper daemon for bhyvemgr
WWW=		https://github.com/alonsobsd/bhyvemgrd

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS?=amd64

USES=		fpc
USE_GITHUB=	yes
GH_ACCOUNT=	alonsobsd

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500000)
ONLY_FOR_ARCHS=	aarch64 amd64
.endif

FPC_LPR_FILE=	${PORTNAME}.lpr

BHYVEMGRD_USER=	bhyvemgrd
BHYVEMGRD_GROUP=bhyvemgrd
USERS=		${BHYVEMGRD_USER}
GROUPS=		${BHYVEMGRD_GROUP}

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

do-build:
	@cd ${WRKSRC}/src && ${LOCALBASE}/bin/fpc ${FPC_LPR_FILE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bhyvemgrd
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/setup/daemon.conf ${STAGEDIR}${PREFIX}/etc/bhyvemgrd/daemon.conf.sample

.include <bsd.port.post.mk>
