# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	1.4.6
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Full featured, no dependency Jail container manager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	pannon
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	41f9863

PLIST_FILES=	etc/rc.d/iocage \
		sbin/iocage \
		man/man8/iocage.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900044
BROKEN=		This port works only on FreeBSD 9 and newer
.endif

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/iocage ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/iocage ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/iocage.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.post.mk>
