# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@gmx.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	0.94.12
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	matthias.andree@gmx.de
COMMENT=	Fast, teachable, learning spam detector

LIB_DEPENDS?=	db-4.3:${PORTSDIR}/databases/db43
.if !defined(WITHOUT_GSL)
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
.endif
.if !defined(WITHOUT_BASH)
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
.endif

CONFLICTS?=	bogofilter-sqlite-[0-9]* bogofilter-tdb-[0-9]* bogofilter-qdbm-[0-9]* [a-z][a-z]-bogofilter-[0-9]*

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
.if defined(WITHOUT_GSL)
CONFIGURE_ARGS+=	--with-included-gsl
.endif
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include/db43" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-ldb-4.3"
CONFIGURE_ENV+=	PERL="${PERL}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=	install-strip prefix=${PREFIX}

MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1 bogotune.1 \
		bf_copy.1 bf_compact.1 bf_resize.1 bf_tar.1

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

pre-everything::
	@${ECHO_CMD} ""
.if !defined(WITHOUT_BASH)
	@${ECHO_CMD} "To install without bash dependency, you can use: make -DWITHOUT_BASH install"
	@${ECHO_CMD} "Note that installing without bash dependency will mean that some of the"
	@${ECHO_CMD} "${DOCSDIR}/contrib scripts will not be installed."
	@${ECHO_CMD} ""
.endif
.if !defined(WITHOUT_GSL)
	@${ECHO_CMD} "To have bogofilter link against its shipped GSL 1.4 statically,"
	@${ECHO_CMD} "you can use: make -DWITHOUT_GSL && make -DWITHOUT_GSL install"
.if !defined(WITHOUT_BASH)
	@${ECHO_CMD} "or: make -DWITHOUT_GSL && make -DWITHOUT_GSL -DWITHOUT_BASH install"
.endif
	@${ECHO_CMD} ""
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
	doc/README.validation TODO \
	RELEASE.NOTES doc/README.db doc/README.sqlite \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO.html doc/bogofilter-SA-2002-01 \
	doc/README.tdb doc/bogofilter-SA-2004-01 GETTING.STARTED \
	doc/bogofilter-faq.html doc/bogofilter-faq-fr.html
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
	${INSTALL_DATA} ${FILESDIR}/ChangeLog.port ${DOCSDIR}
.endif
.if !defined(WITHOUT_BASH)
.for i in randomtrain scramble trainbogo.sh
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/README.randomtrain ${DOCSDIR}/contrib/
.endif
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
