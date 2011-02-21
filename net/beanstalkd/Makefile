# New ports collection makefile for:	beanstalkd
# Date created:							Apr 11, 2008
# Whom:									Vsevolod Stakhov <vsevolod@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beanstalkd
PORTVERSION=	1.4.6
CATEGORIES=	net
MASTER_SITES=	https://github.com/downloads/kr/beanstalkd/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast, distributed, in-memory workqueue service

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	beanstalkd
USE_GMAKE=		yes
GNU_CONFIGURE=	yes
MAKE_ENV+=		EVENT_CFLAGS=-I${LOCALBASE}/include EVENT_LDFLAGS=-L${LOCALBASE}/lib

PLIST_FILES=	bin/beanstalkd

PORTDOCS=		protocol.txt
MAN1=			beanstalkd.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beanstalkd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
