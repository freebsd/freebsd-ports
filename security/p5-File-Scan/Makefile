# New ports collection makefile for:	p5-File-Scan
# Date created:				May 24 2002
# Whom:	      				Martin Matuska <martin@tradex.sk>
#
# $FreeBSD$
#

PORTNAME=	File-Scan
PORTVERSION=	0.80
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File/HDIAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	martin@tradex.sk
COMMENT=	Perl5 anti-virus file scanning package

PERL_CONFIGURE=	yes

MAN3=		File::Scan.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/docs
.for file in Changes FAQ README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in docs/write_sign_bin.txt
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/docs
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/procmail
.for file in latest.pl scan.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.for file in procmail/.procmailrc procmail/README procmail/scanvirus.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}/procmail
.endfor

.include <bsd.port.mk>
