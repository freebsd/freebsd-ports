# ports collection Makefile for: bogofilter
# Whom:		Matthias Andree <matthias.andree@gmx.de>
# Date created:	2002-10-17
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTVERSION=	1.2.1
PORTREVISION?=	2
CATEGORIES?=	mail
MASTER_SITES=	SF/bogofilter/bogofilter-stable/bogofilter-${PORTVERSION}

MAINTAINER?=	mandree@FreeBSD.org
COMMENT=	Fast, teachable, learning spam detector

.if !defined(MASTERDIR) || ${MASTERDIR} == ${.CURDIR}
# building master port
USE_BDB=	41+
.endif

OPTIONS=	GSL     "Link with system-wide GSL dynamically (recommended)" on
OPTIONS+=	UNICODE "Normalize tokens to Unicode (UTF-8)" on

CONFLICTS?=	bogofilter-sqlite-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-tc-[0-9]* [a-z][a-z]-bogofilter-[0-9]*

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 autoheader:262
ACLOCAL_ARGS=	-Im4

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Fails to package on sparc64: fails self-tests
.endif

BF_LIBS?=		-l${BDB_LIB_NAME}
BF_CPPFLAGS?=		-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
.if !defined(WITHOUT_UNICODE)
CONFIGURE_ARGS+=	--enable-unicode
USE_ICONV=		yes
BF_LIBS+=		-liconv
.endif
.if !defined(WITHOUT_GSL)
LIB_DEPENDS+=		gsl.15:${PORTSDIR}/math/gsl
.else
CONFIGURE_ARGS+=	--with-included-gsl
.endif
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" LIBS="${BF_LIBS}" \
		PERL="${PERL}" CPPFLAGS="${BF_CPPFLAGS}"
INSTALL_TARGET=	install-strip prefix=${PREFIX} mandir=${MANPREFIX}/man

MAN1=		bogofilter.1 bogoutil.1 bogoupgrade.1 bogolexer.1 bogotune.1 \
		bf_copy.1 bf_compact.1 bf_tar.1

post-patch:
	${REINPLACE_CMD} -e 's|^#!.*perl|#! ${PERL}|' \
		${WRKSRC}/src/tests/unsort.pl \
		${WRKSRC}/contrib/*.pl
	${REINPLACE_CMD} -e 's/INTEGRITY_TESTS = t.lock1 t.lock3 t.valgrind/INTEGRITY_TESTS = t.lock1/' \
		${WRKSRC}/src/tests/Makefile.in

.if !defined(NOPORTDOCS)
PORTDOCS=	*
PLIST_SUB=	CONTRIB="@comment "
.else
PLIST_SUB=	CONTRIB=""
.endif

post-build::
	cd ${WRKSRC}/src && make check SHELL=${SH}

post-install::
	@${MKDIR} ${DOCSDIR}/contrib
.if !defined(NOPORTDOCS)
.for i in html programmer xml
	@${MKDIR} ${DOCSDIR}/${i}
.endfor
.for i in AUTHORS COPYING INSTALL NEWS README README.svn \
	doc/README.validation TODO GETTING.STARTED \
	RELEASE.NOTES doc/README.db doc/README.sqlite \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO.html doc/bogofilter-SA-* \
	doc/bogofilter-faq.html doc/bogofilter-faq-fr.html
	  ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in README.randomtrain README.contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/trio/AUTHORS ${DOCSDIR}/AUTHORS.trio
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.xml ${DOCSDIR}/xml
	${INSTALL_DATA} ${WRKSRC}/doc/programmer/README.freebsd ${DOCSDIR}/programmer
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bogogrep ${PREFIX}/bin/
.for i in bfproxy.pl bogofilter-milter.pl bogo.R bogofilter-qfe.sh \
		mime.get.rfc822.pl parmtest.sh printmaildir.pl \
		bogominitrain.pl \
		randomtrain.sh scramble.sh spamitarium.pl stripsearch.pl trainbogo.sh
	  ${INSTALL_SCRIPT} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/${i}
.endfor
.for i in dot-qmail-bogofilter-default \
	mailfilter.example procmailrc.example vm-bogofilter.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/${i}
.endfor
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
