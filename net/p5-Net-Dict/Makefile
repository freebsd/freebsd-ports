# New ports collection makefile for:   p5-Net-Dict
# Date created:                21 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Dict
PORTVERSION=	2.06
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	fuyuki@hadaly.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
# if you want to run dict(1):
#RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/AppConfig/Std.pm:${PORTSDIR}/devel/p5-AppConfig-Std
# if you want to run tkdict(1) too:
#RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		dict.1 tkdict.1
MAN3=		Net::Dict.3

post-patch:
	${PERL} -pi -e 's/^&configure.*$$//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
