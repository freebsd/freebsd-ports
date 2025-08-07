PORTNAME=	oc
PORTVERSION=	4.9
DISTVERSIONPREFIX=	release-
PORTREVISION=	31
CATEGORIES=	sysutils

MAINTAINER=	jhixson@freebsd.org
COMMENT=	OpenShift Command Line
WWW=		https://github.com/openshift/oc

LICENSE=	APACHE20
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

USES=		go:modules

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

PLIST_FILES=	bin/oc

USE_GITHUB=	yes
GH_ACCOUNT=	jhixson74
GH_SUBDIR=	src/github.com/openshift/oc

GIT_COMMIT=	ddd7170fca667fef6397f5f27f7a5a41d7769b75

GH_TUPLE=	golang:sys:v0.6.0:sys

GO_BUILDFLAGS=	-ldflags="${STRIP} -w \
				-X github.com/openshift/oc/pkg/version.commitFromGit=${DISTVERSIONPREFIX}${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.versionFromGit=${PORTVERSION} \
				-X github.com/openshift/oc/pkg/version.majorFromGit=${PORTVERSION:S/\.[0-9]+$//} \
				-X github.com/openshift/oc/pkg/version.miniorFromGit=${PORTVERSION:S/^[0-9]+\.//} \
				-X github.com/openshift/oc/pkg/version.gitTreeState=dirty"

GO_TARGET=	./cmd/${PORTNAME}

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
