# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@web.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.15.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	"Fast, teachable, learning spam detector"

# There is a sibling port, bogofilter-tdb, which presets different
# values for some of our variables
LIB_DEPENDS?=	db4.0:${PORTSDIR}/databases/db4

LIB_DEPENDS+=	gsl.5:${PORTSDIR}/math/gsl

CONFLICTS?=	bogofilter-tdb*

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include/db4" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-ldb4"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1 \
		bogol.1 bogotune.1

post-patch:
	${REINPLACE_CMD} -e 's/^@ENABLE_XMLTO_TRUE@//' ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		${WRKSRC}/contrib/randomtrain \
		${WRKSRC}/contrib/scramble \
		${WRKSRC}/contrib/trainbogo.sh

post-build::
	cd ${WRKSRC} && make check SHELL=${SH}

do-install:
	cd ${WRKSRC} && make install-strip prefix=${PREFIX}

post-install::
.for i in bogol.1 bogotune.1
	${INSTALL_MAN} ${WRKSRC}/tuning/${i} ${MAN1PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/contrib
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/programmer
	@${MKDIR} ${DOCSDIR}/tuning
	@${MKDIR} ${DOCSDIR}/tuning/sample.output
	@${MKDIR} ${DOCSDIR}/xml
.for i in AUTHORS COPYING INSTALL NEWS README README.cvs \
	TODO UPGRADE \
	CHANGES-0.10 CHANGES-0.11 CHANGES-0.12 CHANGES-0.13 CHANGES-0.14 \
	CHANGES-0.15 \
	RELEASE.NOTES-0.11 RELEASE.NOTES-0.12 RELEASE.NOTES-0.13 \
	RELEASE.NOTES-0.14 RELEASE.NOTES-0.15 \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO doc/bogofilter-SA-2002-01 METHODS \
	doc/README.tdb
	  ${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/trio/AUTHORS ${DOCSDIR}/AUTHORS.trio
.for i in README.bogotune
	${INSTALL_MAN} ${WRKSRC}/tuning/${i} ${DOCSDIR}/tuning/${i}
.endfor
.for i in bogolex.sh bogol bogotune
	${INSTALL_SCRIPT} ${WRKSRC}/tuning/${i} ${DOCSDIR}/tuning/${i}
.endfor
.for i in tune.nochange tune.normal tune.verbose
	${INSTALL_SCRIPT} ${WRKSRC}/tuning/sample.output/${i} \
		${DOCSDIR}/tuning/sample.output/${i}
.endfor
.for i in contrib/bogo.R contrib/bogofilter-qfe \
		contrib/randomtrain contrib/scramble \
		contrib/mime.get.rfc822 contrib/printmaildir.pl \
		contrib/bogominitrain.pl
	  ${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.for i in contrib/README.randomtrain contrib/dot-qmail-bogofilter-default
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/bogogrep ${DOCSDIR}/contrib/
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.xml ${DOCSDIR}/xml
	${INSTALL_MAN} ${WRKSRC}/doc/programmer/README.freebsd ${DOCSDIR}/programmer
.endif

.include <bsd.port.mk>
