# New ports collection makefile for:	p5-Nagios-Plugin
# Date created:				13 08 2006
# Whom:					Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=		Nagios-Plugin
PORTVERSION=		0.14
CATEGORIES=		net-mgmt perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/T/TO/TONVOON
PKGNAMEPREFIX=		p5-

MAINTAINER=		gerrit.beine@gmx.de
COMMENT=		Object oriented helper routines for Nagios plugin

PERL_CONFIGURE=		yes

MAN3=			Nagios::Plugin.3 \
			Nagios::Plugin::ExitResult.3 \
			Nagios::Plugin::Functions.3 \
			Nagios::Plugin::Getopt.3 \
			Nagios::Plugin::Performance.3 \
			Nagios::Plugin::Range.3 \
			Nagios::Plugin::Threshold.3 \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		This port requires FreeBSD 5-STABLE.
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
