PORTNAME=	vulsrepo
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=v
PORTREVISION=	13
CATEGORIES=	security www
MASTER_SITES=   https://raw.githubusercontent.com/${GH_ACCOUNT}/${PORTNAME}/v${PORTVERSION}/server/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Web presentation layer for vuls CVE scanner
WWW=		https://github.com/ishiDACo/vulsrepo/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

RUN_DEPENDS=	vuls:security/vuls

USES=		go:modules tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	ishiDACo
GH_PROJECT=	vulsrepo

GO_MODULE=	github.com/ishiDACo/vulsrepo/server
WRKSRC_SUBDIR=	server

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message vulsrepo-config.toml
SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS} GROUPS=${GROUPS}

USERS=		vuls
GROUPS=		vuls

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/main.go

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} \
		${STAGEDIR}/var/db/vuls/results \
		${STAGEDIR}/var/log/vuls
	${INSTALL_DATA} ${FILESDIR}/newsyslog-${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-config.toml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}-config.toml.sample
	cd ${WRKSRC}/..; ${PAX} -rw dist gallery index.html plugins \
		${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
