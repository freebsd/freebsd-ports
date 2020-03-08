# $FreeBSD$

PORTNAME=	pkg_jail
PORTVERSION=	2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Manage your own package jail

LICENSE=	BSD3CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dinoex

LMAN1=		allservice.1 check-allservice.1 pkg_jail.1 pkg_update.1
LMAN8=		make-base.8 update-base.8 update-pkg.8

do-install:
	( cd ${WRKSRC} && \
	${INSTALL_SCRIPT} allservice check-allservice pkg_jail pkg_update \
		${STAGEDIR}${PREFIX}/bin/ )
	( cd ${WRKSRC} && \
	${INSTALL_SCRIPT} make-base update-base update-pkg \
		${STAGEDIR}${PREFIX}/sbin/ )
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor
.for i in ${LMAN8}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor

.include <bsd.port.mk>
