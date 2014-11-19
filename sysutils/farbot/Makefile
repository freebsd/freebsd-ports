# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	farbot
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	farbot-1.0-beta2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD Automated Release Bot

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	farb
PYDISTUTILS_PKGVERSION=	0.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/farbot.conf ${STAGEDIR}${PREFIX}/etc/farbot.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${STAGEDIR}${DOCSDIR}/xhtml
.endif

.include <bsd.port.mk>
