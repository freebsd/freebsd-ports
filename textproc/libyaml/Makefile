# Created by: ijliao
# $FreeBSD$

PORTNAME=	libyaml
PORTVERSION=	0.1.6
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/
DISTNAME=	yaml-${PORTVERSION}
DIST_SUBDIR=	repacked

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A YAML 1.1 parser and emitter written in C

GNU_CONFIGURE=	yes
USES=	pathfix
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libyaml.so

.include <bsd.port.mk>
