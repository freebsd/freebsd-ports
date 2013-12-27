# Created by: enigmatyc
# $FreeBSD$

PORTNAME=	rssh
PORTVERSION=	2.3.4
CATEGORIES=	shells security
MASTER_SITES=	SF

MAINTAINER=	jharris@widomaker.com
COMMENT=	Restricted Secure SHell only for sftp or/and scp

GNU_CONFIGURE=	yes

USE_CSTD=	gnu89
OPTIONS_DEFINE=	RDIST
RDIST_DESC=	rdist support
RDIST_RUN_DEPENDS=	rdist6:${PORTSDIR}/net/rdist6
RDIST_CONFIGURE_ON=	--with-rdist=${LOCALBASE}/bin/rdist6

post-patch:
	@${REINPLACE_CMD} -E -e 's,(\$$\(DESTDIR\)\$$\(sysconfdir\)/\$$\$$f),\1.dist,g' \
		-e 's,u\+s ,u+s $$\(DESTDIR\),g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
