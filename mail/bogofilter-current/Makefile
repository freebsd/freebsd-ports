# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@web.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.9.1.2
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@web.de

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

# This port needs PERL5 at run time, but not for the build.
USE_PERL5=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include/db4" \
		LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1

post-build:
	cd ${WRKSRC} && make check SHELL=${SH}

do-install:
	cd ${WRKSRC} && make install prefix=${PREFIX}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS COPYING INSTALL NEWS README TODO UPGRADE \
	doc/integrating-with-qmail contrib/README.unbase64 \
	contrib/dot-qmail-bogofilter-default \
	README.freebsd README.hp-ux README.dcdflib \
	README.Robinson bogofilter-SA-2002-01 METHODS
	  ${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in bogo.R contrib/bogofilter-qfe contrib/unbase64 \
	contrib/bogopass
	  ${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
