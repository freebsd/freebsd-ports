PORTNAME=	dhcpd-pools
PORTVERSION=	3.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME} \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Tool to analyze isc-dhcp pool usage based on leases

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash

USES=		charsetfix shebangfix tar:xz
USE_CSTD=	c99
SHEBANG_FILES=	contrib/snmptest.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dhcpd-conf=${LOCALBASE}/etc/dhcpd.conf \
		--with-dhcpd-leases=/var/db/dhcpd/dhcpd.leases \
		--with-uthash=${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

PORTDATA=	snmptest.pl

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/features.h/d' ${WRKSRC}/src/getdata.c

.include <bsd.port.mk>
