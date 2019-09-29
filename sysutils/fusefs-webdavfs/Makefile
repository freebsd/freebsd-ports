# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs-webdavfs
DISTVERSION=	g20181010
CATEGORIES=	sysutils

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	FUSE filesystem for WEBDAV shares

LICENSE=	BSD3CLAUSE BSD4CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKDIR}/fuse-${FUSE_GH_TAGNAME}/LICENSE
LICENSE_FILE_BSD4CLAUSE=	${WRKDIR}/getopt-${GETOPT_GH_TAGNAME}/LICENSE
LICENSE_FILE_MIT=		${WRKDIR}/webdavfs-${GH_TAGNAME}/LICENSE.md
LICENSE_DISTFILES_MIT=		${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME_fuse}_GH${_GITHUB_REV}${EXTRACT_SUFX}
LICENSE_DISTFILES_BSD4CLAUSE=	${DISTNAME_getopt}_GH${_GITHUB_REV}${EXTRACT_SUFX}

# This needs to be Go 1.7 or newer.
USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	miquels
GH_PROJECT=	webdavfs
GH_TAGNAME=	c03fa01

# 2018-08-11
GETOPT_GH_ACCOUNT=	pborman
GETOPT_GH_PROJECT=	getopt
GETOPT_GH_TAGNAME=	2b5b3bf
GETOPT_WRKSRCDIR=	${GO_WRKSRC}/../src/github.com/${GETOPT_GH_ACCOUNT}/${GETOPT_GH_PROJECT}

# 2018-04-21
FUSE_GH_ACCOUNT=	bazil
FUSE_GH_PROJECT=	fuse
FUSE_GH_TAGNAME=	65cc252
FUSE_WRKSRCDIR=		${GO_WRKSRC}/../src/bazil.org

GH_ACCOUNT+=	${GETOPT_GH_ACCOUNT}:getopt ${FUSE_GH_ACCOUNT}:fuse
GH_PROJECT+=	${GETOPT_GH_PROJECT}:getopt ${FUSE_GH_PROJECT}:fuse
GH_TAGNAME+=	${GETOPT_GH_TAGNAME}:getopt ${FUSE_GH_TAGNAME}:fuse

GO_TARGET=	:${PREFIX}/sbin/mount.webdavfs

PLIST_FILES=	sbin/mount.webdavfs sbin/mount_webdavfs

SUB_FILES=	pkg-message mount_webdavfs

post-patch:
	${GREP} -Flr --include '*.go' '"golang.org/x/net/context"' \
	    ${WRKDIR}/fuse-${FUSE_GH_TAGNAME} ${WRKDIR}/webdavfs-${GH_TAGNAME} |\
	    ${XARGS} ${REINPLACE_CMD} -i '' 's,golang.org/x/net/context,context,'
	${MKDIR} ${GETOPT_WRKSRCDIR} ${FUSE_WRKSRCDIR}
	${LN} -s ${WRKDIR}/getopt-${GETOPT_GH_TAGNAME}/v2 ${GETOPT_WRKSRCDIR}
	${LN} -s ${WRKDIR}/fuse-${FUSE_GH_TAGNAME} ${FUSE_WRKSRCDIR}/fuse

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mount_webdavfs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
