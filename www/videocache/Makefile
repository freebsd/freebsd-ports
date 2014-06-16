# Created by: Murilo Opsfelder <mopsfelder@gmail.com>
# $FreeBSD$

PORTNAME=	videocache
PORTVERSION=	1.9.2
CATEGORIES=	www
MASTER_SITES=	http://secure.thrallingpenguin.com/hosting_files/ \
		http://distcache.freebsd.org/ports-distfiles/ \
		http://old.cachevideos.com/sites/default/files/pub/videocache/

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	Squid URL rewriter for bandwidth optimization

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid \
		${PYTHON_SITELIBDIR}/urlgrabber/grabber.py:${PORTSDIR}/www/py-urlgrabber \
		${PYTHON_SITELIBDIR}/iniparse/ini.py:${PORTSDIR}/devel/py-iniparse

NO_BUILD=	yes
USE_PYTHON=	yes

PORTDOCS=	CHANGELOG COPYING Readme
PORTEXAMPLES=	squid.conf
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/update-vc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/videocache.8.gz ${STAGEDIR}${MAN1PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/videocache-sysconfig.conf ${STAGEDIR}${PREFIX}/etc/videocache.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/videocache/*.py ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/squid.conf.example ${STAGEDIR}${EXAMPLESDIR}/squid.conf
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
