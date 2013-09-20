# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	es
PORTVERSION=	0.9.b1
PORTREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.sys.toronto.edu/pub/es/
DISTNAME=	es-0.9-beta1

MAINTAINER=	ljrittle@acm.org
COMMENT=	An extensible shell, derived from plan9's rc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	es_cv_abused_getenv=no
CONFIGURE_ARGS= --with-readline
CFLAGS:=	${CFLAGS:N-O*}

ALL_TARGET=	es
MAN1=		es.1
PLIST_FILES=	bin/es

NO_STAGE=	yes
.include <bsd.port.mk>
