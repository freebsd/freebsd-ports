# New ports collection makefile for:	confget
# Date created:		18 March 2009
# Whom:			Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	confget
PORTVERSION=	1.01
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/textproc/confget/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

OPTIONS=	PCRE "Regular expression support" on

.include <bsd.port.pre.mk>

.if defined(WITH_PCRE)
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
.else
MAKE_ENV+=	PCRE_CFLAGS= PCRE_LIBS=
.endif

USE_GMAKE=	yes

MAKE_ENV+=	CFLAGS_CONF=-DHAVE_FGETLN

MAN1=		confget.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/confget

test:		build
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
