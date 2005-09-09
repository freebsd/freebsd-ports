# New ports collection makefile for:	nfsen
# Date created:		25 March 2005
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfsen
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://nfsen.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Web based frontend to nfdump netflow collector

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool \
		nfdump:${PORTSDIR}/net-mgmt/nfdump

HAS_CONFIGURE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_PHP=	session pcre
NO_BUILD=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

pre-everything::
.if ${PERL_LEVEL} < 500600
IGNORE=	This backage requires at least perl 5.6.0
.endif

do-configure:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' -e 's,%%PORTNAME%%,${PORTNAME},' \
		${WRKSRC}/etc/nfsen-dist.conf
	${REINPLACE_CMD} -e 's,%%PERL%%,${PERL},' ${WRKSRC}/install.pl

do-install:
	${MKDIR} ${PREFIX}/var/${PORTNAME}/profiles/live
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl ${WRKSRC}/etc/nfsen-dist.conf
	@${ECHO_MSG} "Configure your ${LOCALBASE}/etc/nfsen.conf to have necessary profiles ";
	@${ECHO_MSG} "Then run 'make reconfigure' to correctly setup profile files";

reconfigure:
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl ${LOCALBASE}/etc/nfsen.conf

.include <bsd.port.post.mk>
