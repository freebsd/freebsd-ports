# New ports collection makefile for:   remarp
# Date created:        Tue Apr 1 14:02:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	remarp
PORTVERSION=	0.05
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.raccoon.kiev.ua/projects/remarp/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	An SNMP-based ARP watcher

RUN_DEPENDS=	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP

USE_REINPLACE=	YES
USE_PERL5=	YES
NO_BUILD=	YES

REMARP_SPOOL=	/var/spool/remarp

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|; \
	s|use lib "\$$Bin/../lib";||' ${WRKSRC}/sbin/remarp.pl
	@${REINPLACE_CMD} -e 's|\$$Bin/../etc/remarp.conf|${PREFIX}/etc/remarp.conf|; \
	s|\$$Bin/../var/run/remarp.pid|/var/run/remarp.pid|; \
	s|\$$Bin/../var/spool|${REMARP_SPOOL}|; \
	s|use lib "\$$Bin/../lib";||' ${WRKSRC}/lib/remarp/configure.pm

do-install:
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/remarp
	${MKDIR} ${REMARP_SPOOL}
	${INSTALL_DATA} ${WRKSRC}/etc/remarp.conf ${PREFIX}/etc/remarp.conf.sample
	${INSTALL_DATA} ${WRKSRC}/lib/remarp/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/remarp
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/remarp.pl ${PREFIX}/sbin/remarp

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} "# Please create a remarp config file in ${PREFIX}/etc/                        #"
	@${ECHO_MSG} "# A sample configuration file is installed as remarp.conf.sample              #"
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
