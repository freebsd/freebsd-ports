# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	portfwd
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Port Forwarding Daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
USES=		autoreconf gmake
USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall -ggdb -O3|${CFLAGS}|g" \
		${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e "s|-Wall -g -O3|${CFLAGS}|g" \
		${WRKSRC}/tools/Makefile.am
	@${TOUCH} ${WRKSRC}/* ${WRKSRC}/*/*

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cfg/*.cfg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
