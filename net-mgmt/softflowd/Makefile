# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	softflowd
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	softflowd-
CATEGORIES=	net-mgmt

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Flow-based network traffic analyzer and exporter

LICENSE=	BSD2CLAUSE

USES=		gmake autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	irino
GH_PROJECT=	softflowd

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/softflowd bin/softflowctl \
		man/man8/softflowd.8.gz \
		man/man8/softflowctl.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
