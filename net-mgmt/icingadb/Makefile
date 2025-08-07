PORTNAME=	icingadb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Publish, synchronize, and visualize Icinga data
WWW=		https://icinga.com/docs/icinga-db/latest/doc/02-Installation/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules pgsql

WANT_PGSQL=	contrib

USE_RC_SUBR=	icingadb

PLIST_SUB=	PORTNAME=${PORTNAME}

# As copied from net-mgmt/icinga2
ICINGA2USER?=	icinga
ICINGA2GROUP?=	icinga
USERS=		${ICINGA2USER}
GROUPS=		${ICINGA2GROUP}

SUB_LIST=	ICINGA2GROUP=${ICINGA2GROUP} \
		ICINGA2USER=${ICINGA2USER}

USE_GITHUB=	yes
GH_ACCOUNT=	Icinga
GH_PROJECT=	icingadb

GO_MODULE=	github.com/icinga/icingadb
GO_TARGET=	./cmd/icingadb

SUB_LIST+=	ICINGA2USER=${ICINGA2USER} \
		PREFIX=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX|${PREFIX}|g' ${WRKSRC}/internal/config/config.go

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "schema" ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/config.example.yml ${STAGEDIR}${ETCDIR}/config.yml.sample

.include <bsd.port.mk>
