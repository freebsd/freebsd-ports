# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powerman
PORTVERSION=	2.3.16
PORTREVISION=	1
CATEGORIES=	sysutils parallel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for doing remote power control

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-httppower --localstatedir=${DESTDIR}/var \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USE_RC_SUBR=	powerman

MAN1=		pm.1 powerman.1
MAN3=		libpowerman.3
MAN5=		powerman.conf.5 powerman.dev.5
MAN8=		httppower.8 plmpower.8 powermand.8 vpcd.8

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|:.*|:|' ${WRKSRC}/scripts/Makefile.in

.include <bsd.port.mk>
