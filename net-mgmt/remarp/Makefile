# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	remarp
PORTVERSION=	0.05
CATEGORIES=	net-mgmt
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		http://www.raccoon.kiev.ua/projects/remarp/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	An SNMP-based ARP watcher

RUN_DEPENDS=	p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP

USES=		perl5
NO_BUILD=	YES

REMARP_SPOOL=	/var/spool/remarp

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|; \
	s|use lib "\$$Bin/../lib";||' ${WRKSRC}/sbin/remarp.pl
	@${REINPLACE_CMD} -e 's|\$$Bin/../etc/remarp.conf|${PREFIX}/etc/remarp.conf|; \
	s|\$$Bin/../var/run/remarp.pid|/var/run/remarp.pid|; \
	s|\$$Bin/../var/spool|${REMARP_SPOOL}|; \
	s|use lib "\$$Bin/../lib";||' ${WRKSRC}/lib/remarp/configure.pm

do-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/remarp
	${MKDIR} ${REMARP_SPOOL}
	${INSTALL_DATA} ${WRKSRC}/etc/remarp.conf ${PREFIX}/etc/remarp.conf.sample
	${INSTALL_DATA} ${WRKSRC}/lib/remarp/*.pm ${PREFIX}/${SITE_PERL_REL}/remarp
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
