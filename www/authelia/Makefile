PORTNAME=	authelia
DISTVERSIONPREFIX=	v
DISTVERSION=	4.39.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/authelia/authelia/releases/download/v${DISTVERSION}/:public_html
DISTFILES=	authelia-${DISTVERSIONFULL}-public_html${EXTRACT_SUFX}:public_html # html root directory needs to be built in a special way

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Single sign-on multi-factor portal for web apps
WWW=		https://www.authelia.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.24,modules

GO_MODULE=	github.com/authelia/authelia/v4
GO_TARGET=	./cmd/${PORTNAME}

USER=		root # 'nobody' doesn't work well because authelia attempts to remove files, etc.
SUB_LIST=	USER=${USER}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

post-patch: # extract -public-html
	@${RM} -r ${WRKSRC}/internal/server/public_html
	@${MV} ${WRKDIR}/public_html ${WRKSRC}/internal/server
	@${CP} -r ${WRKSRC}/api ${WRKSRC}/internal/server/public_html/api

post-install: # install the config file
	${INSTALL_DATA} ${WRKSRC}/config.template.yml ${STAGEDIR}${PREFIX}/etc/authelia.yml.sample
	${INSTALL_DATA} ${FILESDIR}/simplified-authelia.yml ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
