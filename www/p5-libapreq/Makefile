# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	p5-libapreq
PORTVERSION= 	0.31
CATEGORIES=     www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     Apache
DISTNAME=	libapreq-0.31

MAINTAINER=	frank@exit.com

BUILD_DEPENDS= 	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/www/apache13 \
		/nonexistent:${PORTSDIR}/www/p5-Apache:extract

USE_PERL5=	YES

MAN3=           Apache::Request.3 Apache::Cookie.3 libapreq.3 Apache::libapreq.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ${PERL} Makefile.PL

post-install:
	${CP} ${WRKSRC}/blib/arch/auto/libapreq/libapreq.so ${LOCALBASE}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
