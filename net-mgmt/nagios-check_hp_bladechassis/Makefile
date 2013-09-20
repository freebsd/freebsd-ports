# Created by: Ryan Steinmetz
# $FreeBSD$

PORTNAME=	check_hp_bladechassis
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://folk.uio.no/trondham/software/files/ \
		http://mirrors.rit.edu/zi/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor your HP Blade Enclosure

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
MAN8=		check_hp_bladechassis.8
PLIST_FILES=	libexec/nagios/check_hp_bladechassis
PLIST_DIRSTRY=	libexec/nagios/

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_hp_bladechassis ${PREFIX}/libexec/nagios/
	${INSTALL_MAN} ${WRKSRC}/check_hp_bladechassis.8 ${PREFIX}/man/man8/

.include <bsd.port.post.mk>
