# New ports collection makefile for:	MHonArc
# Version required:			2.1
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $FreeBSD$
#

DISTNAME=	MHonArc2.3.3
PKGNAME=	mhonarc-2.3.3
CATEGORIES=	www mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://ftp.redhat.com/contrib/noarch/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN/authors/id/EHOOD/

MAINTAINER=	jkoshy@freebsd.org

Y2K=		http://www.oac.uci.edu/indiv/ehood/MHonArc/doc/faq/general.html#y2k

USE_PERL5=	Yes
NO_BUILD=	Yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && ${PERL5} install.me -prefix ${PREFIX} -batch

.include <bsd.port.post.mk>
