PORTNAME=	authelia
DISTVERSIONPREFIX=	v
DISTVERSION=	4.39.28
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/authelia/authelia/releases/download/v${DISTVERSION}/:public_html
DISTFILES=	authelia-${DISTVERSIONFULL}-public_html${EXTRACT_SUFX}:public_html # html root directory needs to be built in a special way

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Single sign-on multi-factor portal for web apps
WWW=		https://www.authelia.com/ \
		https://github.com/authelia/authelia

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.27+,modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/authelia/authelia/v4
GO_TARGET=	./cmd/${PORTNAME}
GO_LDFLAGS=	-X ${GO_MODULE}/internal/utils.BuildTag=${DISTVERSIONFULL} \
		-X "${GO_MODULE}/internal/utils.BuildState=tagged clean"
# go.mk currently omits GO_LDFLAGS when WITH_DEBUG is set.
GO_BUILDFLAGS+=	${WITH_DEBUG:D-ldflags '${GO_LDFLAGS}'}

USER=		root # 'nobody' doesn't work well because authelia attempts to remove files, etc.
SUB_FILES=	pkg-message
SUB_LIST=	USER=${USER}

post-patch: # extract -public-html
	@${RM} -r ${WRKSRC}/internal/server/public_html
	@${MV} ${WRKDIR}/public_html ${WRKSRC}/internal/server
	@${CP} -r ${WRKSRC}/api ${WRKSRC}/internal/server/public_html/api

post-install: # install the config file
	${INSTALL_DATA} ${WRKSRC}/config.template.yml ${STAGEDIR}${PREFIX}/etc/authelia.yml.sample
	${INSTALL_DATA} ${FILESDIR}/simplified-authelia.yml ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
