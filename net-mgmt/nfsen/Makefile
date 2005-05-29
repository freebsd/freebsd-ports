# New ports collection makefile for:	nfsen
# Date created:		25 March 2005
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfsen
PORTVERSION=	1.1r3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rc/}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Web based frontend to nfdump netflow collector

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool \
		nfdump:${PORTSDIR}/net-mgmt/nfdump

HAS_CONFIGURE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_PHP=	session pcre
NO_BUILD=	yes

do-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/etc/nfsen-dist.conf > \
		${WRKSRC}/etc/nfsen.conf

do-install:
	@${MKDIR} -m 755 ${PREFIX}/${PORTNAME}
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl
	@${ECHO_MSG} "Configure your etc/nfsen.conf correctly to have necessary profiles ";

.include <bsd.port.mk>
