# Ports collection makefile for:  sing
# Date created:			  Oct 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	sing
PORTVERSION=	1.1
CATEGORIES=	net-mgmt security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	SING-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@oven.org
COMMENT=	Tool for sending customized ICMP packets

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet \

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-libnet-prefix=${LOCALBASE} --with-libpcap-prefix=/usr
GNU_CONFIGURE=	yes
MAN8=		sing.8
PLIST_FILES=	sbin/sing

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap-* ;\
	${RM} -rf ${WRKSRC}/Libnet-*

.include <bsd.port.mk>
