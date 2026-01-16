PORTNAME=	forgejo
DISTVERSIONPREFIX=	v
DISTVERSION=	14.0.0
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/forgejo/forgejo/releases/download/${DISTVERSIONFULL}/
DISTNAME=	forgejo-src-${DISTVERSION}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Compact self-hosted Git forge
WWW=		https://forgejo.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cpe gmake go:1.25+,no_targets
USE_RC_SUBR=	forgejo

PIE_UNSAFE=	yes

CONFLICTS_INSTALL=	forgejo-lts forgejo7

EXTRACT_AFTER_ARGS=	--strip-components 1
DBDIR=		/var/db/forgejo
LOGDIR=		/var/log/forgejo
SUB_FILES=	app.ini.sample pkg-message
SUB_LIST=	GITUSER=${USERS} DBDIR=${DBDIR} LOGDIR=${LOGDIR}
PLIST_SUB=	DBDIR=${DBDIR} LOGDIR=${LOGDIR}

NO_WRKSUBDIR=	yes

USERS=		git
GROUPS=		git

# If the BINDATA option is off, we will install assets into DATADIR
# and this line ensures that they are included in the packing list.
# Otherwise, assets are compiled into the binary, DATADIR remains
# empty, and this line has no effect.
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

SSP_UNSAFE=	true
LDFLAGS=	"'-X "forgejo.org/modules/setting.CustomPath=${PREFIX}/etc/forgejo"'" \
		"'-X "forgejo.org/modules/setting.AppWorkPath=${DATADIR}"'"
MAKE_ARGS=	GOFLAGS="-buildvcs=false" \
		GOPATH=${WRKDIR} \
		TAGS="${GO_TAGS}"
MAKE_JOBS_UNSAFE=	yes

# The default build target builds both the frontend and the backend.
# However, release tarballs include a prebuilt frontend, so save a
# little time by explicitly building only the backend.
ALL_TARGET=	backend

# Go binaries are statically linked
STRIP=		#

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${forgejo_facility} -s \$${forgejo_priority} -T \
		\$${name}
.else
DAEMONARGS=	-f
.endif
SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

# The provided Makefile does not include an install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitea \
		${STAGEDIR}${PREFIX}/sbin/forgejo
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample \
		${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${WRKSRC}/custom/conf/app.example.ini \
		${STAGEDIR}${ETCDIR}/conf/app.ini.defaults
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DBDIR}/data
	${MKDIR} ${STAGEDIR}${DBDIR}/forgejo-repositories
	${MKDIR} ${STAGEDIR}${LOGDIR}

# If the BINDATA option is off, install assets into DATADIR.
do-install-BINDATA-off:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "options public templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
