# Created by: Martin Matuska <martin@tradex.sk>
# $FreeBSD$

PORTNAME=	File-Scan
PORTVERSION=	1.43
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jims@bluenotch.com
COMMENT=	Perl5 anti-virus file scanning package

USES=		perl5
USE_PERL5=	configure

MAN3=		File::Scan.3

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/docs
.for file in Changes FAQ README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for f in docs/write_sign_bin.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/docs
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/procmail
.for f in latest.pl scan.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.for f in procmail/.procmailrc procmail/README procmail/scanvirus.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}/procmail
.endfor

.include <bsd.port.mk>
