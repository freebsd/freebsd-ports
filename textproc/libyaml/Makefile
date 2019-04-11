# Created by: ijliao
# $FreeBSD$

PORTNAME=	libyaml
PORTVERSION=	0.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/
DISTNAME=	yaml-${PORTVERSION}
DIST_SUBDIR=	repacked

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	YAML 1.1 parser and emitter written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool pathfix

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
CPE_VENDOR=	pyyaml
USE_LDCONFIG=	yes

.include <bsd.port.mk>
