# Created by: Kevin Bowling <k@kev009.com>
# $FreeBSD$

PORTNAME=	nsscache
PORTVERSION=	0.32
PORTREVISION=	1
DISTVERSIONPREFIX=	version/
CATEGORIES=	net python

MAINTAINER=	kbowling@freebsd.org
COMMENT=	Python utility to create a local cache of directory services

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pycurl.so:ftp/py-pycurl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>0:net/py-ldap@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	google

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

.include <bsd.port.mk>
