# New ports collection makefile for: p5-Apache-XBEL
# Date created: August 03 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Apache-XBEL
PORTVERSION=	1.3
# PORTREVISION=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	Apache mod_perl handler to render an XBEL file as an HTML tree

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::XBEL.3

.if defined(NOXSL)
PLIST_SUB+=	XSL="@Comment "
.else
PLIST_SUB+=	XSL=""
post-install:
	@${ECHO} "Installing ${DATADIR}/apache-xbel.xsl"
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/xsl/apache-xbel.xsl ${DATADIR}
.endif

.include <bsd.port.mk>
