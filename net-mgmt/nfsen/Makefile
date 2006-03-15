# New ports collection makefile for:	nfsen
# Date created:		25 March 2005
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	nfsen
PORTVERSION=	1.2.3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://nfsen.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Web based frontend to nfdump netflow collector

RUN_DEPENDS=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/net/rrdtool

.if defined(WITH_IPV6) && !defined(NO_INET6)
RUN_DEPENDS+=	nfdump:${PORTSDIR}/net-mgmt/nfdump-devel
.else
RUN_DEPENDS+=	nfdump:${PORTSDIR}/net-mgmt/nfdump
.endif

USE_ICONV=	yes
USE_PERL5=	yes
USE_PHP=	session pcre
NO_BUILD=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires at least perl 5.6.0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' -e 's,%%PORTNAME%%,${PORTNAME},' \
		${WRKSRC}/etc/nfsen-dist.conf
	@${REINPLACE_CMD} -e 's,%%PERL%%,${PERL},' -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/install.pl
	@${RM} ${WRKSRC}/etc/nfsen-dist.conf.*

do-install:
	@${MKDIR} ${PREFIX}/var/${PORTNAME}/profiles/live
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/installer-items/CopyRecursive.pm ${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/install.pl ${PREFIX}/bin/nfsen-reconfigure
	cd ${WRKSRC} ;${PERL} ${WRKSRC}/install.pl ${WRKSRC}/etc/nfsen-dist.conf
	@${ECHO_MSG} "Configure your ${LOCALBASE}/etc/nfsen.conf to have necessary profiles ";
	@${ECHO_MSG} "Then run 'nfsen-reconfigure ${LOCALBASE}/etc/nfsen.conf' to correctly setup profile files";

.include <bsd.port.post.mk>
