# $FreeBSD$

PORTNAME=	gitlab-pages
PORTVERSION=	1.5.0
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-pages/tags
GL_COMMIT=	869b94c86f7a4eb74b99c0eb6cad92e1d994d1b4

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

post-patch:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/gitlab.com/gitlab-org
	@${LN} -s ${WRKSRC} ${WRKSRC}/src/gitlab.com/gitlab-org/gitlab-pages

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
		go build -o gitlab-pages \
		--ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitlab-pages ${STAGEDIR}${PREFIX}/bin/gitlab-pages

.include <bsd.port.mk>
