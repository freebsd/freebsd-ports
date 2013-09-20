# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scrumburndown
PORTVERSION=	1.9.2
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Plugin to enable Scrum burndown chart capabilities

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		trac-timingandestimation>=0:${PORTSDIR}/www/trac-timingandestimation

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracBurndown
PYDISTUTILS_PKGVERSION=	${PORTVERSION:S/.r/_r/}
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
