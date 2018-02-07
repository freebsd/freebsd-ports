# Created by: asami
# $FreeBSD$

PORTNAME=	igmpproxy
PORTVERSION=	0.2
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	franco@opnsense.org
COMMENT=	Multicast forwarding IGMP proxy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	pali

USE_RC_SUBR=	igmpproxy
USES=		autoreconf
GNU_CONFIGURE=	yes

EXTRA_PATCHES+=	${FILESDIR}/0001-Revert-Try-to-fix-problems-with-strict-aliasing.patch:-p1
EXTRA_PATCHES+= ${FILESDIR}/0002-Revert-Include-config.h-before-any-other-files-to-ma.patch:-p1

post-install:
	${INSTALL_DATA} ${WRKSRC}/igmpproxy.conf \
	    ${STAGEDIR}${PREFIX}/etc/igmpproxy.conf.sample

.include <bsd.port.mk>
