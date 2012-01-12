# New ports collection makefile for:    p5-Authen-OATH
# Date created:				2012-01-12
# Whom:	      				Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Authen-OATH
PORTVERSION=	1.0.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	OATH one time passwords implementation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Digest-SHA1>0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Moose>0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Authen::OATH.3

.include <bsd.port.mk>
