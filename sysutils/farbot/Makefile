# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	farbot
PORTVERSION=	1.0.b2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	farbot-1.0-beta2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD Automated Release Bot

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:devel/py-zconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	farb
PYDISTUTILS_PKGVERSION=	0.1
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/farbot.conf ${STAGEDIR}${PREFIX}/etc/farbot.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/xhtml
	${INSTALL_MAN} ${WRKSRC}/docs/xhtml/* ${STAGEDIR}${DOCSDIR}/xhtml

.include <bsd.port.mk>
