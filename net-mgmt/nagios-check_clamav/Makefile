# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	check_clamav
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Nagios plugin that verifies ClamAV local signature database revision

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

RUN_DEPENDS+=	${LOCALBASE}/libexec/nagios/utils.pm:${PORTSDIR}/net-mgmt/nagios-plugins \
		clamav>=0:${PORTSDIR}/security/clamav \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

PLIST_FILES=	libexec/nagios/check_clamav

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/check_clamav \
		${PREFIX}/libexec/nagios/check_clamav

.include <bsd.port.mk>
