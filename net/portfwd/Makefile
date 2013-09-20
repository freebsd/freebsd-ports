# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	portfwd
PORTVERSION=	0.29
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Port Forwarding Daemon

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN5=	portfwd.cfg.5
MAN8=	portfwd.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|-Wall -ggdb -O3|${CFLAGS}|g" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|-Wall -g -O3|${CFLAGS}|g" \
		${WRKSRC}/tools/Makefile.in
	@${TOUCH} ${WRKSRC}/* ${WRKSRC}/*/*

.if defined(NOPORTDOCS)
post-configure:
	@${REINPLACE_CMD} -e "s|\(^install-data-am:\) install-docDATA|\1|g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		"s|\(^install-data-am: install-man\) install-docDATA|\1|g" \
		${WRKSRC}/doc/Makefile
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/cfg/*.cfg ${EXAMPLESDIR}

.include <bsd.port.mk>
