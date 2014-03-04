# Created by: jabley@clear.co.nz
# $FreeBSD$

PORTNAME=	xfstt
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType font server for X11

OPTIONS_DEFINE=	DOCS

USE_XORG=	fontsproto xproto
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-nls

TTFONTDIR=	${PREFIX}/lib/X11/fonts/TrueType

SUB_FILES=	pkg-message

post-patch:
.for file in INSTALL doc/xfstt.1x src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%TTFONTDIR%%|${TTFONTDIR}|g' ${WRKSRC}/${file}
.endfor
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/xfstt.sh \
		> ${WRKSRC}/xfstt.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xfstt.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${TTFONTDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for _file in CHANGES INSTALL THANKS
	${INSTALL_DATA} ${WRKSRC}/${_file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
