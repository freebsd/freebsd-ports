# New ports collection makefile for:	videocache
# Date created:		2009-04-30
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	videocache
PORTVERSION=	1.9.1
CATEGORIES=	www
MASTER_SITES=	http://cachevideos.com/sites/default/files/pub/videocache/

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A Squid URL rewriter for bandwidth optimization

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid \
		${PYTHON_SITELIBDIR}/urlgrabber/grabber.py:${PORTSDIR}/www/py-urlgrabber \
		${PYTHON_SITELIBDIR}/iniparse/ini.py:${PORTSDIR}/devel/py-iniparse

NO_BUILD=	yes
USE_PYTHON=	yes

MAN8=		videocache.8.gz
PORTDOCS=	CHANGELOG COPYING Readme
PORTEXAMPLES=	squid.conf
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/update-vc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/videocache.8.gz ${MAN1PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/videocache-sysconfig.conf ${PREFIX}/etc/videocache.conf.default
	@[ -f ${PREFIX}/etc/videocache.conf ] || \
		${CP} -v ${PREFIX}/etc/videocache.conf.default ${PREFIX}/etc/videocache.conf
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/videocache/*.py ${DATADIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/squid.conf.example ${EXAMPLESDIR}/squid.conf
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
