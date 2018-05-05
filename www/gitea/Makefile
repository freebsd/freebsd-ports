# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	gitea
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Compact self-hosted Git service

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	go-gitea

GO_PKGNAME=	code.gitea.io/${PORTNAME}
GO_TARGET=	-tags "${GO_TAGS}"

USE_RC_SUBR=	gitea
SUB_FILES+=	app.ini.sample
SUB_LIST+=	GITUSER=${USERS}

USERS=		git
GROUPS=		git

OPTIONS_DEFINE=	CERT PAM SQLITE
CERT_DESC=	Automatic creation of self-signed certificates
PAM_DESC=	Authentication using PAM

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

CERT_VARS=	GO_TAGS+=cert
PAM_VARS=	GO_TAGS+=pam
SQLITE_VARS=	GO_TAGS+=sqlite

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100513
DAEMONARGS=	-S -l \$${gitea_facility} -s \$${gitea_priority} -t \$${name}
.else
DAEMONARGS=	-f
.endif

SUB_LIST+=	DAEMONARGS="${DAEMONARGS}"

post-patch:
	# Gitea releases don't supply the release version number; the
	# automatic method to obtain the version number in the Gitea build
	# system only works when sources are checked out from git.
	# See https://github.com/go-gitea/gitea/issues/1136#issuecomment-311622745
	@${SED} -Ei .orig \
		-e 's#^(var Version = )"[^"]+"#\1"${PORTVERSION}"#' \
		${GO_WRKSRC}/main.go

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${GO_WRKSRC}/custom/conf/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.defaults
	cd ${GO_WRKSRC} && ${COPYTREE_SHARE} "options public templates" ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/log/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/run/${PORTNAME}

.include <bsd.port.mk>
