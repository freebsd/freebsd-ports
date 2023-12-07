PORTNAME=		unbound_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.1
PORTREVISION=		9
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver
WWW=			https://github.com/letsencrypt/unbound_exporter

LICENSE=		APACHE20

USES=			go:modules
USE_GITHUB=		nodefault
GH_TUPLE=		golang:sys:v0.6.0:sys
USE_RC_SUBR=		unbound_exporter
GO_MODULE=		github.com/letsencrypt/unbound_exporter

SUB_FILES=		pkg-message
SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
