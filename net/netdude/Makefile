# ex:ts=8
# New ports collection makefile for: 	netdude
# Date created:			Dec 27, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netdude
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NETwork DUmp data Displayer and Editor for tcpdump tracefiles

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv \
		ltdl.4:${PORTSDIR}/devel/libltdl

USE_REINPLACE=	yes
USE_GNOME=	glib12 gtk12
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lltdl"
USE_GMAKE=	yes
INSTALL_SHLIB=	yes

MAN1=	netdude.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/protocols-fddi::nd_fddi.h.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|gtk-config|${GTK_CONFIG}|g" \
		-e "s|glib-config|${GLIB_CONFIG}|g" ${WRKSRC}/configure
.for file in nd_icmp.c nd_icmp.h nd_icmp_callbacks.c
	@${REINPLACE_CMD} -e "s|struct icmphdr|struct icmp|g" \
		${WRKSRC}/protocols/icmp/${file}
.endfor
	@${REINPLACE_CMD} -e "s|->type|->icmp_type|g" \
		-e "s|->code|->icmp_code|g" \
		-e "s|->checksum|->icmp_cksum|g" \
		-e "s|->un.echo.id|->icmp_id|g" \
		-e "s|->un.echo.sequence|->icmp_seq|g" \
		${WRKSRC}/protocols/icmp/nd_icmp.c

.include <bsd.port.post.mk>
