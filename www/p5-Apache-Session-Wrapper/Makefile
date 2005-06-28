# New ports collection makefile for:	p5-Apache-Session-Wrapper
# Date created:			20 Sep 2004
# Whom:				mat
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-Wrapper
PORTVERSION=	0.21
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A simple wrapper around Apache::Session

BUILD_DEPENDS=	${SITE_PERL}/Class/Container.pm:${PORTSDIR}/devel/p5-Class-Container \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Apache::Session::Wrapper.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

# Depends on devel/p5-Class-Container whichs needs perl 5.6.x or later
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
