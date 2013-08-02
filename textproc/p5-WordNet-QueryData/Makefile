# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WordNet-QueryData
PORTVERSION=	1.49
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the WordNet database files

LIB_DEPENDS=	WN.2:${PORTSDIR}/textproc/wordnet

WNHOME?=	${LOCALBASE}/share/WordNet

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	WNHOME=${WNHOME}

MAN3=		WordNet::QueryData.3

post-patch:
	@${REINPLACE_CMD} -e  \
		'/wnHomeUnix/s|/usr/local/WordNet-3.0|${WNHOME}|; \
		 /wnPrefixUnix/s|/dict||' ${WRKSRC}/QueryData.pm

.include <bsd.port.mk>
