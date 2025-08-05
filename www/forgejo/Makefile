PORTNAME=	forgejo
DISTVERSIONPREFIX=	v
DISTVERSION=	11.0.3
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/forgejo/forgejo/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	forgejo-src-${DISTVERSION}

MAINTAINER=	stb@lassitu.de
COMMENT=	Compact self-hosted Git service
WWW=		https://forgejo.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cpe gmake go:no_targets
USE_RC_SUBR=	forgejo

PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	forgejo[0-79]*

EXTRACT_AFTER_ARGS=	--strip-components 1
SUB_FILES=	app.ini.sample pkg-message
SUB_LIST=	GITUSER=${USERS}

NO_WRKSUBDIR=	yes

USERS=		git
GROUPS=		git

PORTDATA=	*

OPTIONS_DEFINE=		BINDATA GIT_LFS PAM SQLITE
OPTIONS_DEFAULT=	BINDATA GIT_LFS PAM SQLITE
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
DAEMONARGS=	-S -l \$${forgejo_facility} -s \$${forgejo_priority} -T \
		\$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

SSP_UNSAFE=	true
LDFLAGS+=	"'-X "forgejo.org/modules/setting.CustomPath=${PREFIX}/etc/forgejo"'" \
		"'-X "forgejo.org/modules/setting.AppWorkPath=${PREFIX}/share/forgejo"'"
MAKE_ARGS=	GOFLAGS="-buildvcs=false" \
		GOPATH=${WRKDIR} \
		TAGS="${GO_TAGS}"
ALL_TARGET=	backend
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${ECHO_CMD} ${DISTVERSION} >${WRKSRC}/VERSION

# Too lazy to figure out why go install won't work.
do-install:
# Go binary is statically linked and cannot be stripped, so use
# INSTALL_SCRIPT.
	${INSTALL_SCRIPT} ${WRKSRC}/gitea \
		${STAGEDIR}${PREFIX}/sbin/forgejo
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample \
		${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${WRKSRC}/custom/conf/app.example.ini \
		${STAGEDIR}${ETCDIR}/conf/app.ini.defaults
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}/var/db/forgejo/data
	${MKDIR} ${STAGEDIR}/var/db/forgejo/forgejo-repositories
	${MKDIR} ${STAGEDIR}/var/log/forgejo

do-install-BINDATA-off:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "options public templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
