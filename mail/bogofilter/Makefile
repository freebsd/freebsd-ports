# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@web.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.16.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	"Fast, teachable, learning spam detector"

# There is a sibling port, bogofilter-tdb, which presets different
# values for some of our variables
WITH_DB_VER?=	4
.if ${WITH_DB_VER} == 42
LIB_DEPENDS?=	db-4.2:${PORTSDIR}/databases/db42
libs=		-ldb-4.2
.else
WITH_DB_VER=	4
LIB_DEPENDS?=	db4.0:${PORTSDIR}/databases/db4
libs=		-ldb4
.endif

LIB_DEPENDS+=	gsl.5:${PORTSDIR}/math/gsl

CONFLICTS?=	bogofilter-tdb* bogofilter-qdbm*

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include/db${WITH_DB_VER}" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="${libs}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=	install-strip prefix=${PREFIX}

MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1 bogotune.1

post-patch:
	${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		${WRKSRC}/contrib/randomtrain \
		${WRKSRC}/contrib/scramble \
		${WRKSRC}/contrib/trainbogo.sh

.if !defined(PKGNAMESUFFIX) && ${WITH_DB_VER} != 42
pre-everything::
	@${ECHO} ""
	@${ECHO} "Use -DWITH_DB_VER=42 to link against db42 instead of the default db4"
	@${ECHO} ""
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build::
	cd ${WRKSRC} && make check SHELL=${SH}

post-install::
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/contrib
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/programmer
	@${MKDIR} ${DOCSDIR}/xml
.for i in AUTHORS COPYING INSTALL NEWS README README.cvs \
	doc/README.validation TODO \
	CHANGES-* RELEASE.NOTES-* \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO doc/bogofilter-SA-2002-01 METHODS \
	doc/README.tdb
	  ${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/trio/AUTHORS ${DOCSDIR}/AUTHORS.trio
.for i in contrib/bogo.R contrib/bogofilter-qfe \
		contrib/randomtrain contrib/scramble \
		contrib/mime.get.rfc822 contrib/printmaildir.pl \
		contrib/bogominitrain.pl contrib/README.contrib
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
