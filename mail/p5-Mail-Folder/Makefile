# New ports collection makefile for:	p5-Mail-Folder
# Version required:			0.06
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/04/20 21:26:27 jfitz Exp $
#

DISTNAME=	MailFolder-0.06
PKGNAME=	p5-Mail-Folder-0.06
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Mail::Folder.3 Mail::Folder::Emaul.3 Mail::Folder::Mbox.3 Mail::Folder::NNTP.3 Mail::Folder::Maildir.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
