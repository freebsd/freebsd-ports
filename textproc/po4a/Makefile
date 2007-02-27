# New ports collection makefile for:	po4a
# Date created:				08 January 2006
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	po4a
PORTVERSION=	0.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/p/po4a
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation gettext tools

BUILD_DEPENDS=	${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Text/WrapI18N.pm:${PORTSDIR}/textproc/libtext-wrapi18n-perl \
		${SITE_PERL}/SGMLS.pm:${PORTSDIR}/textproc/p5-SGMLSpm \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

USE_GETTEXT=	yes
USE_PERL5=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN3PREFIX=	${TARGETDIR}/lib/perl5/${PERL_VERSION}
MAN3=		Locale::Po4a::TransTractor.3 \
 		Locale::Po4a::LaTeX.3 \
 		Locale::Po4a::Pod.3 \
 		Locale::Po4a::Po.3 \
 		Locale::Po4a::Sgml.3 \
 		Locale::Po4a::Text.3 \
 		Locale::Po4a::Common.3 \
 		Locale::Po4a::KernelHelp.3 \
 		Locale::Po4a::Guide.3 \
 		Locale::Po4a::Man.3 \
 		Locale::Po4a::Xml.3 \
 		Locale::Po4a::Dia.3 \
 		Locale::Po4a::Docbook.3 \
 		Locale::Po4a::Chooser.3 \
 		Locale::Po4a::TeX.3

MAN1=		po4a-translate.1 \
		po4a.1 \
		po4a-normalize.1 \
		msguntypot.1 \
		po4a-updatepo.1 \
		po4a-gettextize.1

.include <bsd.port.mk>
