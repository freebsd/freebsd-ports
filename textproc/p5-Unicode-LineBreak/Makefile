# Created by: Olivier Girard <Olivier.Girard@univ-angers.fr>
# $FreeBSD$

PORTNAME=	Unicode-LineBreak
PORTVERSION=	2012.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

# blanket update approval granted.
MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	Unicode-LineBreak package

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MIME-Charset>=0:${PORTSDIR}/mail/p5-MIME-Charset
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-bundled-sombok \
			--disable-libthai

MAN3=		Unicode::LineBreak.3 \
		Unicode::GCString::JA_JP.3 \
		Text::LineFold.3 \
		Unicode::LineBreak::JA_JP.3 \
		Unicode::GCString.3 \
		Text::LineFold::JA_JP.3

.include <bsd.port.mk>
