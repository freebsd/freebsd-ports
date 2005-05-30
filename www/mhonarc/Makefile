# New ports collection makefile for:	MHonArc
# Date created:				18 June 1997
# Whom:					koshy@india.hp.com
#
# $FreeBSD$
#

PORTNAME=	mhonarc
PORTVERSION=	2.6.11
CATEGORIES=	www mail
MASTER_SITES=	http://www.mhonarc.org/tar/ \
		http://www.oac.uci.edu/indiv/ehood/tar/ \
		http://mirror.ncsa.uiuc.edu/mhonarc.org/\
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://ftp.redhat.com/pub/contrib/noarch/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN-local/authors/id/EHOOD/
DISTNAME=	MHonArc-${PORTVERSION}

MAINTAINER=	max@FreeBSD.org
COMMENT=	WWW front end for mail archives

USE_BZIP2=	Yes
USE_PERL5=	Yes
NO_BUILD=	Yes

MAN1=	mhonarc.1 mha-dbedit.1 mha-dbrecover.1 mha-decode.1

INSTALL_ARGS=	-binpath ${PREFIX}/bin \
		-libpath ${PREFIX}/share/MHonArc \
		-manpath ${PREFIX}/man \
		-batch
.if !defined(NOPORTDOCS)
INSTALL_ARGS+=	-docpath ${PREFIX}/share/doc/MHonArc
.else
INSTALL_ARGS+=	-nodoc
.endif

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && ${PERL5} install.me ${INSTALL_ARGS}

.include <bsd.port.post.mk>
