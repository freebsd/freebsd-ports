# $FreeBSD$

PORTNAME=	amazon-ssm-agent
PORTVERSION=	v1.2.252.0
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Amazon Simple Systems Manager Agent

LICENSE=	Amazon
LICENSE_NAME=	Amazon Software License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash \
		go:lang/go
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_GITHUB=	yes
GH_ACCOUNT=	aws

WRKSRC=		${WRKDIR}/src/github.com/aws/amazon-ssm-agent
USES=		gmake
MAKEFILE=	makefile
ALL_TARGET=	build-freebsd
INSTALL_TARGET=	install-freebsd
MAKE_ARGS=	SKIP_CHECKSTYLE="YES" DESTDIR=${STAGEDIR}${PREFIX}

PLIST_FILES=	etc/amazon/ssm/amazon-ssm-agent.json.template	\
		etc/amazon/ssm/seelog_unix.xml.template		\
		sbin/amazon-ssm-agent

USE_RC_SUBR=	amazon-ssm-agent

post-extract:
	${MKDIR} ${WRKDIR}/src/github.com/aws
	${MV} ${WRKDIR}/${PORTNAME}-${PORTVERSION:S/v//} ${WRKSRC}

.include <bsd.port.mk>
