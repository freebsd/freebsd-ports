PORTNAME=	gatus
DISTVERSIONPREFIX=	v
DISTVERSION=	5.24.0
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Automated developer-oriented status page
WWW=		https://gatus.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	cannot use int64(off) (value of type int64) as int32 value in assignment

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	TwiN

USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	USER=${GATUS_USER}

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.yaml.sample"

GATUS_USER=	www

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/config.yaml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.yaml.sample

.include <bsd.port.mk>
