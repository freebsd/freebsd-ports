# ex:ts=8
# New ports collection makefile for:   jdresolve
# Date created:        15 June 2001
# Whom:                Christophe Labouisse <christophe@labouisse.org>
#
# $FreeBSD$
#

PORTNAME=	jdresolve
PORTVERSION=	0.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.jdrowell.com/static/

MAINTAINER=	christophe@labouisse.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
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
