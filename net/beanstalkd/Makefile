# $FreeBSD$

PORTNAME=	beanstalkd
PORTVERSION=	1.8
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/kr/beanstalkd/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast, distributed, in-memory workqueue service

LICENSE=	MIT

USE_RC_SUBR=	beanstalkd
USE_GMAKE=	yes

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/beanstalkd
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

PORTDOCS=	protocol.txt
MAN1=		beanstalkd.1

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

test: configure
	@cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} check

regression-test: test

.include <bsd.port.mk>
