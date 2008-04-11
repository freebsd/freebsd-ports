# New ports collection makefile for:	beanstalkd
# Date created:							Apr 11, 2008
# Whom:									Vsevolod Stakhov <vsevolod@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beanstalkd
PORTVERSION=	0.10
CATEGORIES=	net
MASTER_SITES=	http://xph.us/software/beanstalkd/rel/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast, distributed, in-memory workqueue service

LIB_DEPENDS=	event-1.3e:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	beanstalkd
USE_GMAKE=	yes
MAKE_ENV+=	EVENT_CFLAGS=-I${LOCALBASE}/include EVENT_LDFLAGS=-L${LOCALBASE}/lib

PLIST_FILES=	bin/beanstalkd

PORTDOCS=		protocol.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/beanstalkd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
