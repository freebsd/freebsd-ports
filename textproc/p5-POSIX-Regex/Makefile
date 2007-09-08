# New ports collection makefile for:	p5-POSIX-Regex
# Date created:		2006-08-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POSIX-Regex
PORTVERSION=	0.89
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POSIX
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	OO interface for the gnu regex engine

PERL_CONFIGURE=	yes
USE_GCC=	3.2+

MAN3=		POSIX::Regex.3

post-patch:
	${PERL} -pi -e 's/REG_NOERROR/0/g' ${WRKSRC}/Regex.xs

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	${SITE_PERL}/ExtUtils/Constant.pm:${PORTSDIR}/devel/p5-ExtUtils-Constant
.endif

.include <bsd.port.post.mk>
