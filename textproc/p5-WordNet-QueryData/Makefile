# New ports collection makefile for:	p5-WordNet-QueryData
# Date created:				07 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WordNet-QueryData
PORTVERSION=	1.33
PORTREVISION=	0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WordNet
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interface to the WordNet database files

LIB_DEPENDS=	wn2:${PORTSDIR}/textproc/wordnet

WNHOME?=	${LOCALBASE}/share/WordNet-2.0

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	WNHOME=${WNHOME}
USE_REINPLACE=	yes

MAN3=		WordNet::QueryData.3

post-patch:
	@${REINPLACE_CMD} -e  \
		'/wnHomeUnix/s|/usr/local/WordNet-2.0|${WNHOME}|; \
		 /wnPrefixUnix/s|/dict||' ${WRKSRC}/QueryData.pm

.include <bsd.port.mk>
