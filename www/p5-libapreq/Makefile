# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	libapreq
PORTVERSION= 	0.31
CATEGORIES=     www perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	frank@exit.com

BUILD_DEPENDS= 	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/include/apache/modules/perl/mod_perl.h:${PORTSDIR}/www/p5-Apache

USE_PERL5=	yes

MAN3=           Apache::Request.3 Apache::Cookie.3 libapreq.3 Apache::libapreq.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"
	@${PERL} -i -p \
		-e 's/^(CC = ).*/$$1 ${CC}/;' \
		-e 's/^(CCFLAGS = ).*/$$1 ${CFLAGS}/' \
		`find ${WRKSRC} -name Makefile`

post-install:
	${INSTALL_DATA} ${WRKSRC}/blib/arch/auto/libapreq/libapreq.so \
		${PREFIX}/lib
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
