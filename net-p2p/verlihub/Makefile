# New ports collection makefile for:	Verlihub
# Date created:				2 April 2004
# Whom:					Bill Cadwallader <hurbold@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	verlihub
DISTVERSION=	0.9.8d-RC2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Verlihub/${DISTVERSION}

MAINTAINER=	skylord@vt.net.ru
COMMENT=	A Direct Connect protocol server (Hub)

# XXX: Actually, bash isn't required for building,
# but otherwise configure script would pick the wrong path
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_RC_SUBR=	verlihub

USE_AUTOTOOLS=	libtool:22
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
SUB_FILES+=	pkg-message

DOCS=		configuring.txt using.txt help.html verlihub.html
MANUAL_DOCS=	verlihub.css verlihub_manual.html
PORTDOCS=	${DOCS} ${MANUAL_DOCS}

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.for i in ${MANUAL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/html_manual/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
