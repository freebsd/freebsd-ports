# New ports collection makefile for:	textproc/p5-Text-ASCIITable
# Date created:				20 April 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-ASCIITable
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create a nice formatted table using ASCII characters

PERL_MODBUILD=	yes

MAN3=	Text::ASCIITable.3 \
	Text::ASCIITable::Wrap.3

post-extract:
	@${MKDIR} ${WRKSRC}/example
	@${MV} ${WRKSRC}/ansi-example.pl ${WRKSRC}/example
	@${PERL} -pi -e '$$_="" if m|ansi-example.pl|' ${WRKSRC}/MANIFEST

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/example/ansi-example.pl ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Example installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
