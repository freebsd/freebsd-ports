# New ports collection makefile for:    pancho
# Date created:                         november 2nd, 2001
# Whom: 				Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
#
# $FreeBSD$
#

PORTNAME=	pancho
PORTVERSION=	9.2.2
CATEGORIES=	net
MASTER_SITES=	http://www.panchoproject.org/archives/pancho/
DISTNAME=	pancho-v${PORTVERSION}

MAINTAINER=	ecu@ipv42.net
COMMENT=	Network devices management tool using TFTP and SNMP

#RUN_DEPENDS=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net/p5-Net-SNMP \
#		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
#		${SITE_PERL}/Parallel/ForkManager.pm:${PORTSDIR}/devel/p5-Parallel-ForkManager

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
	@${MKDIR} ${DOCSDIR}
.for f in README README.plugins Plugin.sample
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
