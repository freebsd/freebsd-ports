# New ports collection makefile for:   synce-rra
# Date created:                March 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-rra
PORTVERSION=	0.8.9
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

PATCH_SITES=	http://sam.stral.net/freebsd/
PATCHFILES=	librra-synce-kde-0.7-freebsd.diff

MAINTAINER=	boris@brooknet.com.au
COMMENT=	Remote Replication Agent Connection protocol library

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir
RUN_DEPENDS=	${LOCALBASE}/lib/libmimedir.a:${PORTSDIR}/devel/libmimedir

MAN1=		synce-matchmaker.1

USE_ICONV=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libsynce=${LOCALBASE}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|sys/types.h|' \
		${WRKSRC}/lib/generator.h ${WRKSRC}/lib/recurrence_internal.h \
		${WRKSRC}/lib/rrac.h

.include <bsd.port.mk>
