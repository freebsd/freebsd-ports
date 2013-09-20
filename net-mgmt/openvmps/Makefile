# Created by: Craig Boston <craig@yekse.gank.org>
# $FreeBSD$

PORTNAME=	openvmps
PORTVERSION=	1.4.05
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/vmps/vmpsd/${PORTVERSION}
DISTNAME=	vmpsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL implementation of the VMPS protocol

LICENSE=	GPLv2

USE_RC_SUBR=	vmpsd

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--bindir=${PREFIX}/sbin

MAN1=		vmpsd.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
IGNORE=		does not run correctly on amd64 architecture, see ports/136376
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-am:/s|install-sysconfDATA||' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/vlan.db ${PREFIX}/etc/vmps.db.sample
.if !exists(${PREFIX}/etc/vmps.db)
	cd ${PREFIX}/etc && ${CP} -p vmps.db.sample vmps.db
.endif

.include <bsd.port.post.mk>
