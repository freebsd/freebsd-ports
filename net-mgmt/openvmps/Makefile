# Created by: Craig Boston <craig@yekse.gank.org>
# $FreeBSD$

PORTNAME=	openvmps
PORTVERSION=	1.4.06
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/vmps/vmpsd/${PORTVERSION}
DISTNAME=	vmpsd-${PORTVERSION}

MAINTAINER=	vladimir.pushkar@gmail.com
COMMENT=	GPL implementation of the VMPS protocol

LICENSE=	GPLv2

USE_RC_SUBR=	vmpsd

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--bindir=${PREFIX}/sbin

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am:/s|install-sysconfDATA||' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/vlan.db ${STAGEDIR}${PREFIX}/etc/vmps.db.sample

.include <bsd.port.mk>
