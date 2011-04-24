# New ports collection makefile for:	security/p5-Module-Signature
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Signature
PORTVERSION=	0.67
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module signature file manipulation

RUN_DEPENDS=	p5-PAR-Dist>=0:${PORTSDIR}/devel/p5-PAR-Dist \
		${LOCALBASE}/bin/gpgv:${PORTSDIR}/security/gnupg1
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		cpansign.1
MAN3=		Module::Signature.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=5.47:${PORTSDIR}/security/p5-Digest-SHA	 
.endif
.include <bsd.port.post.mk>
