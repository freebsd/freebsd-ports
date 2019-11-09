# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	helm
PORTVERSION=	2.16.0
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/danilo

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Package Manager

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go tar:xz

GO_PKGNAME=	k8s.io/helm
GO_BUILDFLAGS=	-ldflags="-X k8s.io/helm/pkg/version.Version=v${PORTVERSION} \
		-X k8s.io/helm/pkg/version.GitCommit=e13bc94621d4ef666270cfbe734aaabf342a49bb \
		-X k8s.io/helm/pkg/version.BuildMetadata="
GO_TARGET=	./cmd/${PORTNAME} \
		./cmd/tiller \
		./cmd/rudder

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

maintainer-distfile:
	(cd /tmp; fetch https://github.com/helm/helm/archive/v${PORTVERSION}.tar.gz; \
		tar xzf v${PORTVERSION}.tar.gz; \
		cd helm-${PORTVERSION}; \
		glide install; \
		${FIND} vendor/ -type d -name vendor -exec ${RM} -r {} +; \
		cd ..; tar cJf helm-${PORTVERSION}.tar.xz helm-${PORTVERSION})

.include <bsd.port.mk>
