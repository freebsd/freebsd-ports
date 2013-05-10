# Created by: Nick F <ffault@gmail.com>
# $FreeBSD$

PORTNAME=	dhcdrop
PORTVERSION=	0.5
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://www.netpatch.ru/projects/dhcdrop/

MAINTAINER=	ffault@gmail.com
COMMENT=	Tool for searching and suppressing false DHCP servers

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN8=		${PORTNAME}.8
MANLANG=	"" ru

PLIST_FILES=	sbin/dhcdrop

OPTIONS_DEFINE=	STATIC
STATIC_DESC=	Build a static version of dhcdrop

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-static-build
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's,inline void rand_ether_addr,static void rand_ether_addr,' \
			${WRKSRC}/src/dhcdrop.[c,h]

.include <bsd.port.mk>
