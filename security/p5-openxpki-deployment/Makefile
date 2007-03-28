# New ports collection makefile for:	p5-openxpki-deployment
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-deployment
PORTVERSION=	0.9.781
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openxpki
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl based enterprise class trustcenter software for PKI

BUILD_DEPENDS=	\
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client \
	${SITE_PERL}/Config/Std.pm:${PORTSDIR}/devel/p5-Config-Std \
	${SITE_PERL}/IO/Prompt.pm:${PORTSDIR}/devel/p5-IO-Prompt \
	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=	openxpki-configure.1 \
	openxpki-metaconf.1 \
	openxpkiadm.1 \
	openxpkictl.1
USE_PERL5=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	openxpki.sh
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}

.include <bsd.port.mk>
