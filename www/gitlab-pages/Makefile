# $FreeBSD$

PORTNAME=	gitlab-pages
PORTVERSION=	1.4.0
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Pages daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the here: https://gitlab.com/gitlab-org/gitlab-pages/tags
GL_COMMIT=	448c37427620cb1794c10394da2a56bd0f575465

PLIST_FILES=	bin/gitlab-pages

USE_RC_SUBR=	gitlab_pages

USERS=		gitlab-pages
GROUPS=		gitlab-pages

post-patch:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/gitlab.com/gitlab-org
	@${LN} -s ${WRKSRC} ${WRKSRC}/src/gitlab.com/gitlab-org/gitlab-pages

do-build:
	cd ${WRKSRC} && ${SETENV} GOCACHE=${WRKSRC}/go CGO_ENABLED=0 GO15VENDOREXPERIMENT=1 \
		GOPATH=${WRKSRC} GOCACHE=off \
		go build -o gitlab-pages \
		--ldflags="-X main.VERSION=${PORTVERSION} -X main.REVISION=${GITHASH}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitlab-pages ${STAGEDIR}${PREFIX}/bin/gitlab-pages

.include <bsd.port.mk>
