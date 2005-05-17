# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@gmx.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.94.11
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-current

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	"Fast, teachable, learning spam detector"

CONFLICTS?=	bogofilter-tdb-[0-9]* bogofilter-qdbm-[0-9]* [a-z][a-z]-bogofilter-[0-9]* \
		bogofilter-[0-9]*

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes

OPTIONS=	DB43	"Use Berkeley DB 4.3 backend"	on \
		TDB	"Use TDB backend"		off \
		SQLITE3	"Use SQLITE 3 backend"		off \
		GSL	"Use GSL library"		on \
		BASH	"Include BASH Scripts"		on \

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_TARGET+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=		install-strip prefix=${PREFIX}

MAN1=			bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1 bogotune.1

.if !defined(WITHOUT_DB43)
LIB_DEPENDS+=		db-4.3:${PORTSDIR}/databases/db43
CONFIGURE_ARGS+=	--with-database=db
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include/db43" LDFLAGS="-L${LOCALBASE}/lib/db43"
.if defined(WITH_TDB) || defined(WITH_SQLITE3)
BROKEN=		"Please select only one DB"
.endif
.endif

.if defined(WITH_TDB)
LIB_DEPENDS+=		tdb.1:${PORTSDIR}/databases/tdb
CONFIGURE_ARGS+=	--with-database=tdb
.if !defined(WITHOUT_DB43) || defined(WITH_SQLITE3)
BROKEN=		"Please select only one DB"
.endif
.endif

.if defined(WITH_SQLITE3)
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-database=sqlite
.if !defined(WITHOUT_DB43) || defined(WITH_TDB)
BROKEN=		"Please select only one DB"
.endif
.endif

.if !defined(WITHOUT_GSL)
LIB_DEPENDS+=		gsl:${PORTSDIR}/math/gsl
CONFIGURE_ARGS+=	--with-included-gsl
.endif

.if !defined(WITHOUT_BASH)
RUN_DEPENDS+=		bash:${PORTSDIR}/shells/bash
.endif

post-patch:
	${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		${WRKSRC}/contrib/randomtrain \
		${WRKSRC}/contrib/scramble \
		${WRKSRC}/contrib/trainbogo.sh
	${REINPLACE_CMD} -e 's|^#!.*perl|#! ${PERL}|' \
		${WRKSRC}/src/tests/unsort.pl \
		${WRKSRC}/contrib/bogofilter-milter.pl \
		${WRKSRC}/contrib/bogominitrain.pl \
		${WRKSRC}/contrib/mime.get.rfc822 \
		${WRKSRC}/contrib/printmaildir.pl

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build::
	cd ${WRKSRC} && make check SHELL=${SH}

post-install::
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in contrib html programmer xml
	@${MKDIR} ${DOCSDIR}/${i}
.endfor
.for i in AUTHORS COPYING INSTALL NEWS README README.cvs \
		doc/README.validation TODO RELEASE.NOTES GETTING.STARTED \
		doc/integrating-with-postfix doc/integrating-with-qmail \
		doc/bogofilter-tuning.HOWTO.html doc/bogofilter-SA-2002-01 \
		doc/README.tdb
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/trio/AUTHORS ${DOCSDIR}/AUTHORS.trio
.for i in contrib/bogo.R contrib/bogofilter-qfe \
		contrib/mime.get.rfc822 contrib/printmaildir.pl \
		contrib/bogominitrain.pl contrib/README.contrib
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.for i in contrib/dot-qmail-bogofilter-default
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/bogogrep ${DOCSDIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.xml ${DOCSDIR}/xml
	${INSTALL_DATA} ${WRKSRC}/doc/programmer/README.freebsd ${DOCSDIR}/programmer
.endif
.if !defined(WITHOUT_BASH)
.for i in randomtrain scramble trainbogo.sh
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/README.randomtrain ${DOCSDIR}/contrib/
.endif
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
