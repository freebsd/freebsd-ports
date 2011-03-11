# New ports collection makefile for:	cfm
# Date created:				23 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfm
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.rpi.edu/~mullr/cfm/dist/
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick Perl/Tk file manager with support for regular expressions

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${PERL} -pi -e 's|#!/usr/bin/perl|#!${PERL}|' ${WRKSRC}/cfm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cfm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/cfm
	${INSTALL_DATA} ${WRKSRC}/example.cfmrc \
		${PREFIX}/share/examples/cfm/dot.cfmrc

.include <bsd.port.mk>
