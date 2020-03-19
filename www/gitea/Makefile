# $FreeBSD$

PORTNAME=	gitea
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/go-gitea/gitea/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	gitea-src-${DISTVERSION}
NO_WRKSUBDIR=	yes

MAINTAINER=	stb@lassitu.de
COMMENT=	Compact self-hosted Git service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		git-lfs:devel/git-lfs

USES=		gmake go:no_targets
USE_RC_SUBR=	gitea

SUB_FILES+=	app.ini.sample
SUB_LIST+=	GITUSER=${USERS}

USERS=		git
GROUPS=		git

OPTIONS_DEFINE=	BINDATA PAM SQLITE
OPTIONS_DEFAULT=	PAM SQLITE
OPTIONS_SUB=	yes

BINDATA_DESC=	Build a single monolithic binary, with all assets included
PAM_DESC=	Enable support for PAM

BINDATA_VARS=	GO_TAGS+=bindata
PAM_VARS=	GO_TAGS+=pam
SQLITE_VARS=	GO_TAGS+="sqlite sqlite_unlock_notify"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
DAEMONARGS=	-S -l \$${gitea_facility} -s \$${gitea_priority} -T \$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

SSP_UNSAFE=	true
# use sane defaults for path, overriden with actual PREFIX in start script
EXTRA_LDFLAGS=	-X code.gitea.io/gitea/modules/setting.CustomPath=${PREFIX}/etc/gitea
EXTRA_LDFLAGS+=	-X code.gitea.io/gitea/modules/setting.AppWorkPath=${PREFIX}/share/gitea
# Default LDFLAGS are incompatible with build
MAKE_ENV=	LDFLAGS="${LDFLAGS} ${EXTRA_LDFLAGS}"
MAKE_ARGS=	GOPATH=${WRKDIR} TAGS="${GO_TAGS}"
ALL_TARGET=	backend
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${ECHO_CMD} ${DISTVERSION} >${WRKSRC}/VERSION

# Too lazy to figure out why go install won't work.
do-install:
	# Go binary is statically linked and cannot be stripped, so use
	# INSTALL_SCRIPT.
	${INSTALL_SCRIPT} ${WRKSRC}/gitea ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${WRKSRC}/custom/conf/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.defaults

	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/log/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/run/${PORTNAME}

do-install-BINDATA-off:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "options public templates" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
