# New ports collection makefile for:	Xfstt
# Date created:				11 September 1998
# Whom:					jabley@clear.co.nz
#
# $FreeBSD$
#

PORTNAME=	xfstt
PORTVERSION=	1.6
CATEGORIES=	x11-servers
MASTER_SITES=	http://download.berlios.de/xfstt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A TrueType font server for X11

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var --disable-nls

MAN1=		xfstt.1x

TTFONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

post-patch:
.for file in INSTALL doc/xfstt.1x src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%TTFONTDIR%%|${TTFONTDIR}|g' ${WRKSRC}/${file}
.endfor
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/xfstt.sh \
		> ${WRKSRC}/xfstt.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xfstt.sh ${PREFIX}/etc/rc.d
	@${MKDIR} ${TTFONTDIR}
.if !defined{NOPORTDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES INSTALL THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
