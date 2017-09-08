# Created by: Joe Barbish
# $FreeBSD$

PORTNAME=	qjail
PORTVERSION=	5.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	qjail1@a1poweruser.com
COMMENT=	Utility to quickly deploy and manage jails

LICENSE=	BERNE-CONVENTION
LICENSE_NAME=	Berne Convention
LICENSE_TEXT=	As per the international "Berne Convention" this work is \
		protected and all rights reserved. \
		Before qjail may be forked, written permission must be \
		obtained from the author <qjail1@a1poweruser.com>. \
		This work is provided 'AS IS' and you use it at your own risk. \
		Redistribution and use is permitted providing this license \
		notice is retained.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

IGNORE_FreeBSD_10=	This version only for FreeBSD 11+

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qjail                      \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/qjail.bootime              \
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA}   ${WRKSRC}/qjail.portsnap.conf        \
		${STAGEDIR}${PREFIX}/etc/qjail.portsnap.conf.sample
.for i in qjail qjail-intro qjail-howto qjail-vnet-howto \
	qjail-ipv6-testing
	${INSTALL_MAN}   ${WRKSRC}/${i}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor

# note examples are mandatory. qjail will not function without them
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ \
		&& ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
