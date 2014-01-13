# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	subtickets
PORTVERSION=	0.2.0.${GITDATE}
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		https://github.com/itota/trac-subtickets-plugin/tarball/${GITVERSION}/
PKGNAMEPREFIX=	trac-
DISTNAME=	itota-trac-subtickets-plugin-a0fc153

MAINTAINER=	gaod@hychen.org
COMMENT=	Offers sub-ticket feature for managing tickets

LICENSE=	BSD

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

GITVERSION=	a0fc153
GITDATE=	20130328

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
WRKSRC=		${WRKDIR}/itota-trac-${PORTNAME}-plugin-${GITVERSION}
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	TracSubTicketsPlugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION:C/${GITDATE}//g}dev
PLIST_FILES=		bin/check-trac-subtickets \
			%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
.include <bsd.port.mk>
