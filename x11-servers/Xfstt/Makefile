# New ports collection makefile for:	Xfstt
# Date created:				11 September 1998
# Whom:					jabley@clear.co.nz
#
# $FreeBSD$
#

PORTNAME=	xfstt
PORTVERSION=	1.4
CATEGORIES=	x11-servers
MASTER_SITES=	http://download.berlios.de/xfstt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A TrueType font server for X11

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-nls

MAN1=		xfstt.1x

TTFONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

post-patch:
.for file in INSTALL doc/xfstt.1x src/perftest.cc src/xfstt.cc
	@${REINPLACE_CMD} -e 's|%%TTFONTDIR%%|${TTFONTDIR}|g' ${WRKSRC}/${file}
.endfor

post-install:
	${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/xfstt.sh \
		> ${PREFIX}/etc/rc.d/xfstt.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/xfstt.sh
	@${MKDIR} ${TTFONTDIR}
.if !defined{NOPORTDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES INSTALL THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
