# Created by: torstenb
# $FreeBSD$

PORTNAME=	metamail
PORTVERSION=	2.7
PORTREVISION=	13
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/ \
		ftp://ftp.research.telcordia.com/pub/nsb/
DISTNAME=	mm${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

LICENSE=	MIT

USES=		tar:Z

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_DESC=		X11 hebrew font support
X11_BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
			mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
X11_RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
			mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
X11_USE=		XORG=x11

post-patch-X11-off:
	@${REINPLACE_CMD} -e '/fonts/d' ${WRKSRC}/Makefile

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/mailcap ${STAGEDIR}${PREFIX}/etc/mailcap.sample

.include <bsd.port.mk>
