# New ports collection makefile for:	farbot
# Date created:		29 November 2006
# Whom:			Nick Barkas <snb@threerings.net>
#
# $FreeBSD$

PORTNAME=	farbot
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dpw.threerings.net/projects/farbot/
DISTNAME=	farbot-1.0-beta2

MAINTAINER=	snb@FreeBSD.org
COMMENT=	FreeBSD Automated Release Bot

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	farb
PYDISTUTILS_PKGVERSION=	0.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/farbot.conf ${PREFIX}/etc/farbot.conf.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${DOCSDIR}/xhtml
.endif

.include <bsd.port.mk>
