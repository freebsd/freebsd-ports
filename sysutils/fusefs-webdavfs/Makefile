# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs-webdavfs
DISTVERSION=	g20180413
CATEGORIES=	sysutils

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	FUSE filesystem for WEBDAV shares

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/fuse-${FUSE_GH_TAGNAME}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	miquels
GH_PROJECT=	webdavfs
GH_TAGNAME=	c503b3c

# 2017-01-13
GETOPT_GH_ACCOUNT=	pborman
GETOPT_GH_PROJECT=	getopt
GETOPT_GH_TAGNAME=	7148bc3
GETOPT_WRKSRCDIR=	${GO_WRKSRC}/../src/github.com/${GETOPT_GH_ACCOUNT}/${GETOPT_GH_PROJECT}

# 2018-04-21
FUSE_GH_ACCOUNT=	bazil
FUSE_GH_PROJECT=	fuse
FUSE_GH_TAGNAME=	65cc252
FUSE_WRKSRCDIR=		${GO_WRKSRC}/../src/bazil.org

GH_ACCOUNT+=	${GETOPT_GH_ACCOUNT}:getopt ${FUSE_GH_ACCOUNT}:fuse
GH_PROJECT+=	${GETOPT_GH_PROJECT}:getopt ${FUSE_GH_PROJECT}:fuse
GH_TAGNAME+=	${GETOPT_GH_TAGNAME}:getopt ${FUSE_GH_TAGNAME}:fuse

PLIST_FILES=	sbin/mount.webdavfs sbin/mount_webdavfs

SUB_FILES=	pkg-message mount_webdavfs

# This needs to be Go 1.7 or newer.
USES=		go

post-patch:
	${GREP} -Flr '"golang.org/x/net/context"' ${WRKDIR} |\
	    ${XARGS} ${REINPLACE_CMD} -i '' 's,golang.org/x/net/context,context,'
	${MKDIR} ${GETOPT_WRKSRCDIR} ${FUSE_WRKSRCDIR}
	${LN} -s ${WRKDIR}/getopt-${GETOPT_GH_TAGNAME}/v2 ${GETOPT_WRKSRCDIR}
	${LN} -s ${WRKDIR}/fuse-${FUSE_GH_TAGNAME} ${FUSE_WRKSRCDIR}/fuse

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/mount.webdavfs
	${INSTALL_SCRIPT} ${WRKDIR}/mount_webdavfs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
