# New ports collection makefile for:   jdresolve
# Date created:        15 June 2001
# Whom:                Christophe Labouisse <christophe@labouisse.org>
#
# $FreeBSD$
#

PORTNAME=	jdresolve
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.jdrowell.com/projects/jdresolve/
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-0.6.2b1.diff

MAINTAINER=	christophe@labouisse.org
COMMENT=	A IP addresse to hostname program for httpd log files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes

MANCOMPRESSED=	no
MAN1=	rhost.1 jdresolve.1

DOC1=	AUTHORS BUGS CHANGELOG COPYING CREDITS INSTALL README TODO

do-install:
.for file in jdresolve rhost
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${file}.1 ${MAN1PREFIX}/man/man1
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jdresolve
.for i in ${DOC1}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/jdresolve
.endfor
.endif

.include <bsd.port.mk>
