# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@web.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.13.6.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@web.de
COMMENT=	"Fast, teachable, learning spam detector"

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db4" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-ldb4"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1

post-build::
	cd ${WRKSRC} && make check SHELL=${SH}

do-install:
	cd ${WRKSRC} && make install-strip prefix=${PREFIX}

.if !defined(NOPORTDOCS)
post-install::
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/contrib
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/programmer
	@${MKDIR} ${DOCSDIR}/tuning
	@${MKDIR} ${DOCSDIR}/xml
.for i in AUTHORS COPYING INSTALL NEWS README README.cvs \
	TODO UPGRADE \
	CHANGES-0.10 CHANGES-0.11 CHANGES-0.12 CHANGES-0.13 \
	RELEASE.NOTES-0.11 RELEASE.NOTES-0.12 RELEASE.NOTES-0.13 \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO doc/bogofilter-SA-2002-01 METHODS
	  ${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in README setR tuning.R
	${INSTALL_MAN} ${WRKSRC}/tuning/${i} ${DOCSDIR}/tuning/
.endfor
.for i in bogolex.sh distrib mkdb sizes tuning.sh
	${INSTALL_SCRIPT} ${WRKSRC}/tuning/${i} ${DOCSDIR}/tuning/
.endfor
.for i in contrib/bogo.R contrib/bogofilter-qfe \
		contrib/randomtrain contrib/scramble \
		contrib/mime.get.rfc822 contrib/printmaildir.pl
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
