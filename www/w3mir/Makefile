# New ports collection makefile for:    w3mir
# Version required:                     1*
# Date created:                         9 May 1998
# Whom:                                 ache
#
# $Id: Makefile,v 1.13 1998/11/15 15:29:18 ache Exp $
#

DISTNAME=       w3mir-1.0.5
CATEGORIES=     www perl5
MASTER_SITES=   http://www.math.uio.no/~janl/w3mir/

MAINTAINER=     ache@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	Yes

MAN1=           w3mir.1 w3mfix.1

do-configure:
		@ cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${PERL} Makefile.PL PREFIX=${PREFIX} \
				     INSTALLMAN1DIR=${PREFIX}/man/man1 \
				     INSTALLSCRIPT=${PREFIX}/bin
post-install:
		${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
			${PREFIX}/share/doc/w3mir
		cd ${WRKSRC} && ${INSTALL_DATA} \
			README Artistic w3mir-HOWTO.html example.cfg \
			multiscope.cfg ${PREFIX}/share/doc/w3mir

.include <bsd.port.mk>
