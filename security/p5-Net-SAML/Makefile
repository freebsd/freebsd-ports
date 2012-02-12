# New ports collection makefile for:	p5-Net-SAML
# Date created:		2007-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SAML
PORTVERSION=	1.05
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	zxid-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for using SAML SSO

LICENSE=	AL2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		zxid:${PORTSDIR}/security/zxid

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Net

MAN3=		Net::SAML.3

post-patch:
	@${REINPLACE_CMD} -e 's|/apps/openssl/std|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/../ && ${INSTALL_SCRIPT} zxid.pl zxidhlo.pl ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
