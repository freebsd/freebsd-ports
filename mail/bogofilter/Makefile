# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@web.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.10.2
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
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc --with-db=defeat-guessing
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1

post-build:
	cd ${WRKSRC} && make check SHELL=${SH}

do-install:
	cd ${WRKSRC} && make install-strip prefix=${PREFIX}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/contrib
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/programmer
	@${MKDIR} ${DOCSDIR}/xml
.for i in AUTHORS CHANGES-0.10 COPYING INSTALL NEWS README README.cvs \
	TODO UPGRADE \
	doc/integrating-with-qmail \
	doc/README.Robinson doc/bogofilter-SA-2002-01 METHODS
	  ${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in contrib/bogo.R contrib/bogofilter-qfe \
		contrib/randomtrain contrib/scramble
	  ${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DOCSDIR}/contrib
.endfor
.for i in contrib/README.randomtrain contrib/dot-qmail-bogofilter-default
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/contrib
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/bogogrep ${DOCSDIR}/contrib
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.xml ${DOCSDIR}/xml
	${INSTALL_MAN} ${WRKSRC}/doc/programmer/README.* ${DOCSDIR}/programmer
.endif

.include <bsd.port.mk>
