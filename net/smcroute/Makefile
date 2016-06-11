# $FreeBSD$

PORTNAME=	smcroute
PORTVERSION=	2.1.0
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Static multicast routing tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	troglobit
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin
INSTALL_TARGET=	install-exec-am install-man
PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

OPTIONS_DEFINE=	DOCS
DOCS_INSTALL_TARGET=	install

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
