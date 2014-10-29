# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pxe
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PXE daemon, set up a boot menu for netbooting PXE enabled clients

USE_RC_SUBR=	pxe
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-config=${PREFIX}/etc/pxe.conf \
			--with-log=/var/log/pxe.log \
			--with-setuid=nobody

PORTDOCS=	Changes INSTALL LICENCE README THANKS
PLIST_FILES=	sbin/pxe etc/pxe.conf.sample

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|/tmp/pxe.pid|/var/run/pxe.pid|' \
		${WRKSRC}/autoconf.h.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxe ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pxe.conf \
		${STAGEDIR}${PREFIX}/etc/pxe.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
