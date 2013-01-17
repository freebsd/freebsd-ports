# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-MechanicalTurk
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl interface to the Amazon Mechanical Turk

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Net-SSLeay>=1.33:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA
BUILD_DEPENDS:=	${RUN_DEPENDS}

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
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${INSTALL} -d ${EXAMPLESDIR}/{} \;
	@cd ${WRKSRC}/samples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
