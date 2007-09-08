# New ports collection makefile for:	p5-Net-SSLeay
# Date created:				April 17th 2000
# Whom:	      				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SSLeay
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DISTNAME=	Net_SSLeay.pm-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to SSL

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	"${OPENSSLBASE}"
USE_OPENSSL=	yes

MAN3=		Net::SSLeay.3 Net::SSLeay::Handle.3

SRCDIR=		${WRKSRC}/examples

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${SRCDIR}/*.pl ${EXAMPLESDIR}/
	${INSTALL_DATA} ${SRCDIR}/req.conf ${EXAMPLESDIR}/req.conf
.endif

.include <bsd.port.mk>
