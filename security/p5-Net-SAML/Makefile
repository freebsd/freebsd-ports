# New ports collection makefile for:	p5-Net-SAML
# Date created:		2007-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SAML
PORTVERSION=	0.44
CATEGORIES=	security perl5
MASTER_SITES=	http://zxid.org/
PKGNAMEPREFIX=	p5-
DISTNAME=	zxid-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for using SAML SSO

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		zxid:${PORTSDIR}/security/zxid

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Net

post-patch:
	${REINPLACE_CMD} -e 's!/apps/openssl/std!${LOCALBASE}!' \
		${WRKSRC}/Makefile.PL

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/../zxid.pl    ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/../zxidhlo.pl ${EXAMPLESDIR}

MAN3=		Net::SAML.3

.include <bsd.port.mk>
