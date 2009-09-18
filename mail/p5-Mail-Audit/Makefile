# New ports collection makefile for:	Mail-Audit
# Date created:				Wed Jan  3 12:31:10 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-Audit
PORTVERSION=	2.2.24
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9]+)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for creating easy mail filters

RUN_DEPENDS=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-File-HomeDir>=0.61:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/File/Tempdir.pm:${PORTSDIR}/devel/p5-File-Tempdir \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::Audit.3 \
		Mail::Audit::KillDups.3 \
		Mail::Audit::MAPS.3 \
		Mail::Audit::MailInternet.3 \
		Mail::Audit::MimeEntity.3 \
    		Mail::Audit::Util::Tempdir.3 \
		Mail::Audit::Vacation.3

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	Changes FAQ README
PORTEXAMPLES=	popread proc2ma

post-patch:
	@${PERL} -pi -e 's,/var/spool/mail,/var/mail,g' ${WRKSRC}/lib/Mail/Audit.pm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for i in ${PORTEXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${i}  ${EXAMPLESDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
