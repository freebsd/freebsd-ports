# New ports collection makefile for:   synce-rra
# Date created:                March 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-rra
PORTVERSION=	0.9.1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Remote Replication Agent Connection protocol library

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir
RUN_DEPENDS=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir

MAN1=		synce-matchmaker.1

USE_ICONV=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libsynce=${LOCALBASE}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' ${WRKSRC}/lib/rrac.h \
		${WRKSRC}/lib/generator.h
.endif

.include <bsd.port.post.mk>
