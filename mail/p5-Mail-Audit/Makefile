# New ports collection makefile for:	Mail-Audit
# Date created:				Wed Jan  3 12:31:10 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Audit
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl module for creating easy mail filters

BUILD_DEPENDS=	${SITE_PERL}/Net/Config.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	     	${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/ListDetector.pm:${PORTSDIR}/mail/p5-Mail-ListDetector \
		${SITE_PERL}/${PERL_ARCH}/Razor2/Client/Agent.pm:${PORTSDIR}/mail/razor-agents
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Audit.3 \
		Mail::Audit::KillDups.3 \
		Mail::Audit::List.3 \
		Mail::Audit::MAPS.3 \
		Mail::Audit::PGP.3 \
		Mail::Audit::Razor.3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples//${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${PERL} -pi -e 's,/var/spool/mail,/var/mail,g' ${WRKSRC}/Audit.pm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changes FAQ README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for file in popread proc2ma
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} \
		${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
