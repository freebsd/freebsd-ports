# New ports collection makefile for:    pancho
# Date created:                         november 2nd, 2001
# Whom: 				Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$
#

PORTNAME=	pancho
PORTVERSION=	9.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.panchoproject.org/archives/pancho/
DISTNAME=	pancho-v${PORTVERSION}

MAINTAINER=	ecu@ipv42.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SNMP.pm:${PORTSDIR}/net/p5-Net-SNMP \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parallel/ForkManager.pm:${PORTSDIR}/devel/p5-Parallel-ForkManager

WRKSRC=		${WRKDIR}/Pancho-${PORTVERSION}
USE_PERL5=	YES
PERL_CONFIGURE=	YES

MAN1=		pancho.1

post-patch:
	@${MV} ${WRKSRC}/lib/Pancho/Plugins/README ${WRKSRC}/README.plugins
	@${MV} ${WRKSRC}/lib/Pancho/Plugins/Plugin.sample ${WRKSRC}/

post-install:
	@${INSTALL_DATA} ${WRKSRC}/samples/sample.conf ${PREFIX}/etc/pancho.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for f in README README.plugins Plugin.sample
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif
.include <bsd.port.mk>
