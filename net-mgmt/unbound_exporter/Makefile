PORTNAME=		unbound_exporter
PORTVERSION=		0.4.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=		net-mgmt

MAINTAINER=		aduitsis@cpan.org
COMMENT=		Prometheus metrics exporter for the Unbound DNS resolver
WWW=			https://github.com/letsencrypt/unbound_exporter

LICENSE=		APACHE20

USES=			go:modules
USE_RC_SUBR=		unbound_exporter
GO_MODULE=		github.com/letsencrypt/unbound_exporter

SUB_FILES=		pkg-message
SUB_LIST=		USERS=${USERS} GROUPS=${GROUPS}

USERS=			unbound
GROUPS=			unbound

PLIST_FILES=		bin/unbound_exporter

.include <bsd.port.mk>
