# $FreeBSD$

PORTNAME=	beanstalkd
PORTVERSION=	1.10
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast, distributed, in-memory workqueue service

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
USE_RC_SUBR=	beanstalkd

GH_ACCOUNT=	kr

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/beanstalkd man/man1/beanstalkd.1.gz
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

PORTDOCS=	protocol.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beanstalkd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

test: configure
	@cd ${WRKSRC} && ${MAKE_CMD} ${MAKE_ARGS} check

regression-test: test

.include <bsd.port.mk>
