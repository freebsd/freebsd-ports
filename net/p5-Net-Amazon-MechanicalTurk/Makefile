# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-MechanicalTurk
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
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

USES=		perl5 shebangfix
USE_PERL5=	configure

SUB_LIST+=	HOME=${HOME} EXAMPLESDIR=${EXAMPLESDIR}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*
SHEBANG_FILES=	mturk_install.pl

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/{} \;
	@cd ${WRKSRC}/samples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR}/{} \;

.include <bsd.port.mk>
