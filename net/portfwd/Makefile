# New ports collection makefile for:	portfwd
# Date created:         Sun May 5 16:12:30 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	portfwd
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Port Forwarding Daemon

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN5=	portfwd.cfg.5
MAN8=	portfwd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall -ggdb -O3|${CFLAGS}|g" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|-Wall -g -O3|${CFLAGS}|g" \
		${WRKSRC}/tools/Makefile.in

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
	@${INSTALL_DATA} ${WRKSRC}/cfg/* ${EXAMPLESDIR}

.include <bsd.port.post.mk>
