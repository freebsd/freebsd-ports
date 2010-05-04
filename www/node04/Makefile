# New ports collection makefile for:		node
# Date created:					2010-04-12
# Whom:						Jin-Sih Lin <linpct@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	node
PORTVERSION=	0.1.93
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 javascript for client and server

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes

ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST}
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} tools/waf-light --jobs=${MAKE_JOBS_NUMBER} build)

.include <bsd.port.mk>
