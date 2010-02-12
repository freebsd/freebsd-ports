# New ports collection makefile for:	swaks
# Date created:				29 Sep 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	swaks
PORTVERSION=	20100211.0
CATEGORIES=	mail
MASTER_SITES=	http://jetmore.org/john/code/swaks/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Swiss Army Knife SMTP transaction tester

PLIST_FILES=	bin/${PORTNAME}

OPTIONS=	PERL_NET_DNS "Add MX lookup support" off \
		PERL_NET_SSLEAY "Add TLS support" off \
		PERL_AUTHEN_NTLM "Add support for AUTH NTLM" off

USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_PERL_NET_DNS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

.if defined(WITH_PERL_NET_SSLEAY)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay
.endif

.if defined(WITH_PERL_AUTHEN_NTLM)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Authen/NTLM.pm:${PORTSDIR}/security/p5-Authen-NTLM
.endif

do-build:
	@${SED} -e '1s|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
