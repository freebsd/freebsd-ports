# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	1.6.2
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Full featured, no dependency Jail container manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	pannon
GH_TAGNAME=	5a228b0

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900044
BROKEN=		This port works only on FreeBSD 9 and newer
.endif

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/lib/iocage|${PREFIX}/lib/iocage|g" ${WRKSRC}/iocage

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/iocage

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/iocage ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/iocage ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/iocage)
	${INSTALL_MAN} ${WRKSRC}/iocage.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.post.mk>
