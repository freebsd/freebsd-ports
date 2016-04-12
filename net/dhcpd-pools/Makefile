# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcpd-pools
PORTVERSION=	2.28
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Tool to analyze isc-dhcp pool usage based on leases

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash

USES=		charsetfix shebangfix tar:xz
SHEBANG_FILES=	contrib/snmptest.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dhcpd-conf=${LOCALBASE}/etc/dhcpd.conf \
		--with-dhcpd-leases=/var/db/dhcpd/dhcpd.leases \
		--with-uthash=${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/dhcpd-pools \
		man/man1/dhcpd-pools.1.gz \
		%%DATADIR%%/nagios.conf
PORTDATA=	dhcpd-pools.cgi snmptest.pl

post-patch:
	@${REINPLACE_CMD} -e '/features.h/d' ${WRKSRC}/src/getdata.c

.include <bsd.port.mk>
