# New ports collection makefile for:	p5-Log-Procmail
# Date created:				2004-04-26
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Log-Procmail
PORTVERSION=	0.11
CATEGORIES=	mail devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading procmail logfiles

PERL_CONFIGURE=	yes

MAN1=		mailstat.pl.1
MAN3=		Log::Procmail.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
