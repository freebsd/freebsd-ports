# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	softflowd
PORTVERSION=	0.9.9
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/softflowd/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Flow-based network traffic analyzer and exporter

LICENSE=	BSD2CLAUSE

USES=		gmake
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	sbin/softflowd sbin/softflowctl \
		man/man8/softflowd.8.gz \
		man/man8/softflowctl.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
