# New ports collection makefile for:    w3mir
# Version required:                     1*
# Date created:                         9 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.9 1998/09/15 21:31:58 asami Exp $
#

DISTNAME=       w3mir-1.0.4pre2
PKGNAME=        w3mir-1.0.4p2
CATEGORIES=     www perl5
MASTER_SITES=   http://www.math.uio.no/~janl/w3mir/

MAINTAINER=     ache@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	Yes

MAN1=           w3mir.1 w3mfix.1

do-configure:
		@ cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${PERL} Makefile.PL PREFIX=${PREFIX} \
				     INSTALLMAN1DIR=${PREFIX}/man/man1
post-install:
		${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
			${PREFIX}/share/doc/w3mir
		cd ${WRKSRC} && ${INSTALL_DATA} \
			README Artistic w3mir-HOWTO.html example.cfg \
			multiscope.cfg ${PREFIX}/share/doc/w3mir

.include <bsd.port.mk>
