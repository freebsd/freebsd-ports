# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	check_clamav
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Nagios plugin that verifies ClamAV local signature database revision

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	check_clamav

RUN_DEPENDS+=	${LOCALBASE}/libexec/nagios/utils.pm:net-mgmt/nagios-plugins \
		clamav>=0:security/clamav \
		p5-Net-DNS>=0:dns/p5-Net-DNS

PLIST_FILES=	libexec/nagios/check_clamav

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_clamav \
		${STAGEDIR}${PREFIX}/libexec/nagios/check_clamav

.include <bsd.port.mk>
