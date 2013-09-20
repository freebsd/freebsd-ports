# Created by: Elias Mandouvalos <ocean@compulink.gr>
# $FreeBSD$

PORTNAME=	tn5250
PORTVERSION=	0.17.4
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	5250 Telnet protocol and Terminal

USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-os-dir=no --with-ssl=${OPENSSLBASE}
USE_LDCONFIG=	yes

MAN1=		lp5250d.1 scs2ascii.1 scs2pdf.1 scs2ps.1 tn5250.1
MAN5=		tn5250rc.5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS =/s|linux||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-data-local|:|g' ${WRKSRC}/freebsd/Makefile.in

.include <bsd.port.mk>
