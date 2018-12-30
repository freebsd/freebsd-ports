# Created by: Kevin Bowling <kbowling@freebsd.org>
# $FreeBSD$

PORTNAME=	nsscache
PORTVERSION=	0.37
DISTVERSIONPREFIX=	version/
CATEGORIES=	net python

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Python utility to create a local cache of directory services

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:databases/py-bsddb@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pycurl.so:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>0:net/py-ldap@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mox>0:devel/py-mox@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	google

NO_ARCH=	yes

PLIST_FILES=	'@sample etc/nsscache.conf.sample' '@dir /var/db/nsscache' \
		man/man1/nsscache.1.gz man/man5/nsscache.conf.5.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/nsscache.conf|${PREFIX}/etc/nsscache.conf|g' ${WRKSRC}/nss_cache/config.py
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/nsscache.conf
	@${REINPLACE_CMD} -e "s|/var/lib/misc|/var/db/nsscache|g" ${WRKSRC}/nsscache.conf.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/nsscache.conf ${STAGEDIR}${PREFIX}/etc/nsscache.conf.sample
	${INSTALL_MAN} ${WRKSRC}/nsscache.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nsscache.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}/var/db/nsscache

do-test:
	${PYTHON_CMD} ${WRKSRC}/runtests.py

.include <bsd.port.mk>
