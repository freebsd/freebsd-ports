# New ports collection makefile for: hunch
# Date created:		26 October 2002
# Whom:			Dan Pelleg <daniel+hunch@pelleg.org>
#
# $FreeBSD$
#

PORTNAME=	hunch
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://web.cs.cmu.edu/~dpelleg/download/

MAINTAINER=	daniel+hunch@pelleg.org
COMMENT=	Scan httpd log files, find vulnerability probes, mail admins

RUN_DEPENDS=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net

IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_PACKAGE=	too interactive
NO_BUILD=	true
USE_PERL5=	YES

do-install:
	@${ECHO_MSG} "Installing files"
	@${INSTALL_DATA} ${WRKSRC}/etc/hunch-special ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/complain-httpd ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/contact ${PREFIX}/bin

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
