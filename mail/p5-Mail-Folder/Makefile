# New ports collection makefile for:	p5-Mail-Folder
# Version required:			0.03
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1996/11/17 07:42:42 obrien Exp $
#

DISTNAME=	MailFolder-0.03
PKGNAME=	p5-Mail-Folder-0.03
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Mail::Folder.3 Mail::Folder::Emaul.3 Mail::Folder::Mbox.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
