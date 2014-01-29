# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	farbot
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	farbot-1.0-beta2

MAINTAINER=	snb@FreeBSD.org
COMMENT=	FreeBSD Automated Release Bot

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	farb
PYDISTUTILS_PKGVERSION=	0.1

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/farbot.conf ${PREFIX}/etc/farbot.conf.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${DOCSDIR}/xhtml
.endif

.include <bsd.port.mk>
