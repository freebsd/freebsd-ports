# New ports collection makefile for:	MHonArc
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $FreeBSD$
#

PORTNAME=	mhonarc
PORTVERSION= 	2.4.6
CATEGORIES=	www mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://ftp.redhat.com/contrib/noarch/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN/authors/id/EHOOD/
DISTNAME=	MHonArc2.4.6

MAINTAINER=	jkoshy@freebsd.org

Y2K=		http://www.oac.uci.edu/indiv/ehood/MHonArc/doc/faq/general.html#y2k

USE_BZIP2=	Yes
USE_PERL5=	Yes
NO_BUILD=	Yes

MAN1=	mhonarc.1 mha-dbedit.1 mha-dbrecover.1 mha-decode.1

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && ${PERL5} install.me -binpath ${PREFIX}/bin \
		-docpath ${PREFIX}/share/doc/MHonArc \
		-libpath ${PREFIX}/share/MHonArc \
		-manpath ${PREFIX}/man -batch

.include <bsd.port.post.mk>
