# New ports collection makefile for:	p5-libapreq
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	libapreq
PORTVERSION=	1.1
CATEGORIES=	www perl5 devel
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=     ../../authors/id/J/JI/JIMW/
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache Request Library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Cookie.3 Apache::Request.3 Apache::libapreq.3 \
		libapreq.3

post-patch:
	@${PERL} -pi~ -e '$$_="" if $$. >8 && $$. <27' ${WRKSRC}/Makefile.PL

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/c/testapreq
	@${MKDIR} ${EXAMPLESDIR}/perl
	${INSTALL_DATA} ${WRKSRC}/eg/c/testapreq/* ${EXAMPLESDIR}/c/testapreq
	${INSTALL_SCRIPT} ${WRKSRC}/eg/perl/* ${EXAMPLESDIR}/perl
.endif

.include <bsd.port.mk>
