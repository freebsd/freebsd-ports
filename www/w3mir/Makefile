# New ports collection makefile for:    w3mir
# http://www.sn.no/libwww-perl/
# Version required:                     1.0.2
# Date created:                         9 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.17 1998/04/28 14:45:37 vanilla Exp $
#

DISTNAME=       w3mir-1.0.2
CATEGORIES=     www perl5
MASTER_SITES=   http://www.math.uio.no/~janl/w3mir/

MAINTAINER=     ache@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	YES

MAN1=           w3mir.1 w3mfix.1

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
