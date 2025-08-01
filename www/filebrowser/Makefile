PORTNAME=	filebrowser
DISTVERSIONPREFIX=	v
DISTVERSION=	2.42.1
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Web File Browser
WWW=		https://filebrowser.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/filebrowser/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'github.com/filebrowser/${PORTNAME}/v2/version.Version=${DISTVERSION}' \
			-X 'github.com/filebrowser/${PORTNAME}/v2/version.CommitSHA=${GITID}'"

SUB_LIST=	USER=${USERS:[1]}

USERS=		${FILEBROWSER_USER}
GROUPS=		${FILEBROWSER_GROUP}

PLIST_SUB=	GROUP=${GROUPS:[1]} \
		USER=${USERS:[1]}

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the File Browser repository to get the value of GITID.
GITID=		af9b42549ff5db3305e0bee51387dd763beeff9f

FILEBROWSER_USER=	${PORTNAME}
FILEBROWSER_GROUP=	${FILEBROWSER_USER}

pre-build:
	@cd ${WRKDIR}/filebrowser-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/frontend/dist

post-install:
.for dir in run log db
	@${MKDIR} ${STAGEDIR}/var/${dir}/${PORTNAME}
.endfor

.include <bsd.port.mk>
