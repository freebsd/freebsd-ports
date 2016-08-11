# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	portfwd
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Port Forwarding Daemon

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall -ggdb -O3|${CFLAGS}|g" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|-Wall -g -O3|${CFLAGS}|g" \
		${WRKSRC}/tools/Makefile.in
	@${TOUCH} ${WRKSRC}/* ${WRKSRC}/*/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cfg/*.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
