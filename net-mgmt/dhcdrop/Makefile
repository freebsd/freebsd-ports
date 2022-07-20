PORTNAME=	dhcdrop
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://www.netpatch.ru/projects/dhcdrop/

MAINTAINER=	ffault@gmail.com
COMMENT=	Tool for searching and suppressing false DHCP servers

LICENSE=	GPLv2

USES=		autoreconf libtool tar:bzip2
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/dhcdrop man/man8/dhcdrop.8.gz \
		man/ru/man8/dhcdrop.8.gz

OPTIONS_DEFINE=	STATIC
STATIC_DESC=	Build a static version of dhcdrop

# --disable-static-build is broken and has the same effect as
# --enable-static-build, so do not use STATIC_CONFIGURE_ENABLE
# here.
STATIC_CONFIGURE_ON=	--enable-static-build

.if exists(/usr/lib/libibverbs.a)
# Link with libibverbs too needed by static libpcap
post-patch-STATIC-on:
	@${REINPLACE_CMD} -e 's,^dhcdrop_LDADD.*,& -libverbs,' \
		${WRKSRC}/src/Makefile.am
.endif

.include <bsd.port.mk>
