# Created by: enigmatyc
# $FreeBSD$

PORTNAME=	rssh
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	shells security
MASTER_SITES=	SF

MAINTAINER=	jharris@widomaker.com
COMMENT=	Restricted Secure SHell only for sftp/scp/rdist/rsync/CVS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes

USES=		cpe
CPE_VENDOR=	pizzashack
USE_CSTD=	gnu89
OPTIONS_DEFINE=	RDIST RSYNC3
RDIST_DESC=	rdist support
RDIST_RUN_DEPENDS=	rdist6:net/rdist6
RDIST_CONFIGURE_ON=	--with-rdist=${LOCALBASE}/bin/rdist6

RSYNC3_DESC=		rsync3 support (Debian patch)
RSYNC3_EXTRA_PATCHES=	${FILESDIR}/optional-patch-util.c

post-patch:
	@${REINPLACE_CMD} -E -e 's,(\$$\(DESTDIR\)\$$\(sysconfdir\)/\$$\$$f),\1.dist,g' \
		-e 's,u\+s ,u+s $$\(DESTDIR\),g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
