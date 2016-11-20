# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	gitea
PORTVERSION=	0.9.100
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	stb@lassitu.de
COMMENT=	Compact self-hosted Git service

LICENSE=	MIT

RUN_DEPENDS=	git:devel/git

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	go-gitea
GH_TAGNAME=	cf045b0

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
SQLITE=		Add SQLite as database backend

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MCERT}
GO_TAGS+=	cert
.endif
.if ${PORT_OPTIONS:MPAM}
GO_TAGS+=	pam
.endif
.if ${PORT_OPTIONS:MSQLITE}
GO_TAGS+=	sqlite
.endif

post-stage:
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/run/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${STAGEDIR}${ETCDIR}/conf/app.ini.sample
	${INSTALL_DATA} ${GO_WRKSRC}/conf/app.ini ${STAGEDIR}${ETCDIR}/conf/app.ini.defaults
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${GO_WRKSRC} && ${COPYTREE_SHARE} "public templates" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
