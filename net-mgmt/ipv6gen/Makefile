# New ports collection makefile for:    ipv6gen
# Date created:                         4 April 2005
# Whom:                                 Vladimir Kotal <vlada@devnull.cz>
#
# $FreeBSD$
#

PORTNAME=	ipv6gen
PORTVERSION=	1.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://techie.devnull.cz/ipv6/ipv6gen/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vlada@devnull.cz
COMMENT=	IPv6 prefix generator

MAN1=	${PORTNAME}.1

NO_BUILD=
USE_PERL5_RUN=	yes
PLIST_FILES=	bin/${PORTNAME} bin/check-overlap
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 \
	${WRKSRC}/ipv6gen.pl ${PREFIX}/bin/ipv6gen
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0755 \
	${WRKSRC}/check-overlap.pl ${PREFIX}/bin/check-overlap
	${INSTALL_MAN} ${WRKSRC}/ipv6gen.1 ${PREFIX}/man/man1/ipv6gen.1

.include <bsd.port.mk>
