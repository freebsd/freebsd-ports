# New ports collection makefile for:	p5-Nagios-Plugins-Memcached
# Date created:				18 Dec 2007
# Whom:					Philp M. Gollucci <pgollucci@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Nagios-Plugins-Memcached
PORTVERSION=	0.02
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/Z/ZI/ZIGOROU
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Module to check memcached via nagios

PERL_CONFIGURE=	yes

BUILD_DEPENDS+=	${SITE_PERL}/Nagios/Plugin.pm:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
		${SITE_PERL}/Cache/Memcached.pm:${PORTSDIR}/databases/p5-Cache-Memcached \
		${SITE_PERL}/Carp/Clan.pm:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=		Nagios::Plugins::Memcached.3
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${LOCALBASE}/libexec/nagios
	${INSTALL} ${WRKSRC}/bin/check_memcached ${LOCALBASE}/libexec/nagios/check_memcached
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
