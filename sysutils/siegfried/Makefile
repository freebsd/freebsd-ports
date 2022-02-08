# Created by: Steffen Fritz <steffen@fritz.wtf>

PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File identification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	richardlehane

GO_TARGET=	./cmd/sf
GH_TUPLE=       \
                golang:image:6944b10bf410:golang_image/vendor/golang.org/x/image \
                golang:sys:da31bd327af9:golang_sys/vendor/golang.org/x/sys \
                golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
                richardlehane:characterize:v1.0.0:richardlehane_characterize/vendor/github.com/richardlehane/characterize \
                richardlehane:match:v1.0.0:richardlehane_match/vendor/github.com/richardlehane/match \
                richardlehane:mscfb:v1.0.4:richardlehane_mscfb/vendor/github.com/richardlehane/mscfb \
                richardlehane:msoleps:v1.0.1:richardlehane_msoleps/vendor/github.com/richardlehane/msoleps \
                richardlehane:webarchive:v1.0.0:richardlehane_webarchive/vendor/github.com/richardlehane/webarchive \
                richardlehane:xmldetect:v1.0.2:richardlehane_xmldetect/vendor/github.com/richardlehane/xmldetect \
                ross-spencer:spargo:v0.4.1:ross_spencer_spargo/vendor/github.com/ross-spencer/spargo \
                ross-spencer:wikiprov:v0.2.0:ross_spencer_wikiprov/vendor/github.com/ross-spencer/wikiprov

PLIST_FILES=	bin/sf

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} \
		./cmd/sf

.include <bsd.port.mk>
