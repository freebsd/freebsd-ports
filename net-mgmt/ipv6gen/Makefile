# Created by: Vladimir Kotal <vlada@devnull.cz>
# $FreeBSD$

PORTNAME=	ipv6gen
PORTVERSION=	1.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vlada@devnull.cz
COMMENT=	IPv6 prefix generator

MAN1=	${PORTNAME}.1

NO_BUILD=
USES=		perl5
USE_PERL5=	run
PLIST_FILES=	bin/${PORTNAME} bin/check-overlap
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 \
	${WRKSRC}/ipv6gen.pl ${PREFIX}/bin/ipv6gen
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 \
	${WRKSRC}/check-overlap.pl ${PREFIX}/bin/check-overlap
	${INSTALL_MAN} ${WRKSRC}/ipv6gen.1 ${PREFIX}/man/man1/ipv6gen.1

.include <bsd.port.mk>
