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

.include <bsd.port.mk>
