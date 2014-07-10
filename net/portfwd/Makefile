# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	portfwd
PORTVERSION=	0.29
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Port Forwarding Daemon

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall -ggdb -O3|${CFLAGS}|g" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|-Wall -g -O3|${CFLAGS}|g" \
		${WRKSRC}/tools/Makefile.in
	@${TOUCH} ${WRKSRC}/* ${WRKSRC}/*/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/cfg/*.cfg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
