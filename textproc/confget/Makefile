# New ports collection makefile for:	confget
# Date created:		18 March 2009
# Whom:			Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	confget
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://devel.ringlet.net/textproc/confget/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Read variables from INI-style configuration files

OPTIONS=	PCRE "Regular expression support" on

.include <bsd.port.pre.mk>

.if defined(WITH_PCRE)
LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre
.else
MAKE_ENV+=	PCRE_CFLAGS= PCRE_LIBS=
.endif

USE_GMAKE=	yes

MAKE_ENV+=	CFLAGS_CONF=-DHAVE_FGETLN

MAN1=		confget.1
MANCOMPRESSED=	yes

.if defined(NOPORTEXAMPLES)
post-patch:
		${REINPLACE_CMD} -E -e 's/([^n])install-examples/\1/' \
			${WRKSRC}/Makefile
.else
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}
.endif

test:		build
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
