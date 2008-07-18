# New ports collection makefile for:	p5-Net-Amazon-MechanicalTurk
# Date created:		2007-10-29
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon-MechanicalTurk
PORTVERSION=	1.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl interface to the Amazon Mechanical Turk

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::MechanicalTurk.3 \
		Net::Amazon::MechanicalTurk::BulkSupport.3 \
		Net::Amazon::MechanicalTurk::Command::AddRetry.3 \
		Net::Amazon::MechanicalTurk::Command::DeleteHIT.3 \
		Net::Amazon::MechanicalTurk::Command::GetAvailableBalance.3 \
		Net::Amazon::MechanicalTurk::Command::GetHITTypeURL.3 \
		Net::Amazon::MechanicalTurk::Command::ListOperations.3 \
		Net::Amazon::MechanicalTurk::Command::LoadHITs.3 \
		Net::Amazon::MechanicalTurk::Command::ParseAssignmentAnswer.3 \
		Net::Amazon::MechanicalTurk::Command::RetrieveResults.3 \
		Net::Amazon::MechanicalTurk::Command::UpdateHITs.3

SUB_LIST+=	HOME=${HOME} EXAMPLESDIR=${EXAMPLESDIR}
SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
