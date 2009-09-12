# ex:ts=8
# Ports collection makefile for:	libyaml
# Date created:			Aug 31, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libyaml
PORTVERSION=	0.1.3
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/
DISTNAME=	yaml-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A YAML 1.1 parser and emitter written in C

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/yaml.h \
		lib/libyaml-0.so \
		lib/libyaml-0.so.2 \
		lib/libyaml.a \
		lib/libyaml.so \
		lib/libyaml.la

.include <bsd.port.mk>
