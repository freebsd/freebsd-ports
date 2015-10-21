# $FreeBSD$

PORTNAME=	vm-bhyve
PORTVERSION=	0.8.12
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	churchers@gmail.com
COMMENT=	Management system for bhyve virtual machines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC=	Install example guest templates

USE_GITHUB=	yes
GH_ACCOUNT=	churchers
GH_TAGNAME=	24b6b35

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
BROKEN=		This port works only on FreeBSD 10 and newer
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vm ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/vm ${STAGEDIR}${PREFIX}/etc/rc.d
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/vm-bhyve)
	(cd ${WRKSRC}/sample-templates/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/vm.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
