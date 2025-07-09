PORTNAME=	gitea
DISTVERSIONPREFIX=	v
DISTVERSION=	1.24.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/go-gitea/gitea/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/ \
		https://dl.gitea.io/gitea/${DISTVERSION}/
DISTNAME=	gitea-src-${DISTVERSION}

MAINTAINER=	stb@lassitu.de
COMMENT=	Compact self-hosted Git service
WWW=		https://gitea.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cpe gmake go:no_targets
USE_RC_SUBR=	gitea

EXTRACT_AFTER_ARGS=	--strip-components 1 # since 1.17.0, archive includes gitea-src-VERSION directory
SUB_FILES+=	app.ini.sample pkg-message
SUB_LIST+=	GITUSER=${USERS}

NO_WRKSUBDIR=	yes

USERS=		git
GROUPS=		git

PORTDATA=	*

OPTIONS_DEFINE=		BINDATA GIT_LFS PAM SQLITE
OPTIONS_DEFAULT=	GIT_LFS PAM SQLITE
OPTIONS_SUB=		yes

BINDATA_DESC=	Build a single monolithic binary, with all assets included
GIT_LFS_DESC=	Support for Git Large File Storage (LFS)
PAM_DESC=	Enable support for PAM

BINDATA_VARS=		GO_TAGS+=bindata
GIT_LFS_RUN_DEPENDS=	git-lfs:devel/git-lfs
PAM_VARS=		GO_TAGS+=pam
SQLITE_VARS=		GO_TAGS+="sqlite sqlite_unlock_notify"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${gitea_facility} -s \$${gitea_priority} -T \$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

SSP_UNSAFE=	true
LDFLAGS+=	"'-X "code.gitea.io/gitea/modules/setting.CustomPath=${PREFIX}/etc/gitea"'"
LDFLAGS+=	"'-X "code.gitea.io/gitea/modules/setting.AppWorkPath=${PREFIX}/share/gitea"'"
MAKE_ARGS=	GOPATH=${WRKDIR} TAGS="${GO_TAGS}" GOFLAGS="-buildvcs=false"
ALL_TARGET=	backend
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${ECHO_CMD} ${DISTVERSION} >${WRKSRC}/VERSION

# Too lazy to figure out why go install won't work.
do-install:
	# Go binary is statically linked and cannot be stripped, so use
	# INSTALL_SCRIPT.
	${INSTALL_SCRIPT} ${WRKSRC}/gitea ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf \
		 ${STAGEDIR}${DATADIR} \
		 ${STAGEDIR}/var/db/gitea \
		 ${STAGEDIR}/var/db/gitea/data \
		 ${STAGEDIR}/var/db/gitea/gitea-repositories \
		 ${STAGEDIR}/var/log/gitea
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${WRKSRC}/custom/conf/app.example.ini ${STAGEDIR}${ETCDIR}/conf/app.ini.defaults

do-install-BINDATA-off:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "options public templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
