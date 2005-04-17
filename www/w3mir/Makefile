# New ports collection makefile for:    w3mir
# Date created:                         9 May 1998
# Whom:                                 ache
#
# $FreeBSD$
#

PORTNAME=	w3mir
PORTVERSION=    1.0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=   http://langfeldt.net/w3mir/

MAINTAINER=	ache@freebsd.org
COMMENT=	All-purpose HTTP copying and mirroring tool

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes

MAN1=		w3mir.1 w3mfix.1

INSTALL_TARGET= pure_install

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
