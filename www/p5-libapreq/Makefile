# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	libapreq
PORTVERSION=	0.31_03
CATEGORIES=	www perl5 devel
MASTER_SITES=	http://www.cpan.org/authors/id/J/JI/JIMW/
PKGNAMEPREFIX=	p5-

MAINTAINER=	frank@exit.com

BUILD_DEPENDS=	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/include/apache/modules/perl/mod_perl.h:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		Apache::Request.3 Apache::Cookie.3 libapreq.3 Apache::libapreq.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-configure:
	@${PERL} -i -p \
		-e 's/^(CC = ).*/$$1 ${CC}/;' \
		-e 's/^(CCFLAGS = ).*/$$1 ${CFLAGS}/' \
		`find ${WRKSRC} -name Makefile`

post-install:
	${INSTALL_DATA} ${WRKSRC}/blib/arch/auto/libapreq/libapreq.so \
		${PREFIX}/lib

.include <bsd.port.mk>
