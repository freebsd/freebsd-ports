# New ports collection makefile for:	MHonArc
# Version required:			2.1
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $Id: Makefile,v 1.8 1998/12/01 08:38:55 asami Exp $
#

DISTNAME=	MHonArc2.3.3
PKGNAME=	mhonarc-2.3.3
CATEGORIES=	www mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://contrib.redhat.com/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN/authors/id/EHOOD/

MAINTAINER=	jkoshy@freebsd.org

Y2K=		http://www.oac.uci.edu/indiv/ehood/MHonArc/doc/faq/general.html#y2k

USE_PERL5=	Yes
NO_BUILD=	Yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300003
BROKEN=		installs in /usr/local/local/lib/perl5
.endif

do-install:
	cd ${WRKSRC} && ${PERL5} install.me -prefix ${PREFIX} -batch

.include <bsd.port.post.mk>
