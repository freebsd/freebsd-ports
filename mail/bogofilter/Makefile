# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	bogofilter
DISTVERSION=	1.2.5
PORTREVISION?=	1
CATEGORIES?=	mail
MASTER_SITES=	SF/bogofilter/bogofilter-stable/

MAINTAINER?=	mandree@FreeBSD.org
COMMENT=	Fast, teachable, learning spam detector

LICENSE=	GPLv2

.if !defined(MASTERDIR) || ${MASTERDIR} == ${.CURDIR}
# building master port
USES+=		bdb:5+
.endif

OPTIONS_DEFINE=		GSL UNICODE DOCS
OPTIONS_DEFAULT=	GSL UNICODE
GSL_DESC=		Link with system-wide GSL dynamically (recommended)
UNICODE_DESC=		Normalize tokens to Unicode (UTF-8) (recommended)

CONFLICTS_INSTALL?=	bogofilter-sqlite-[0-9]* bogofilter-tc-[0-9]* bogofilter-lmdb-[0-9]* \
			bogofilter-kc-[0-9]*

# XXX FIXME: autoreconf:build should not be required,
# but something hoses timestamps on src/tests/Makefile.am
# but not src/tests/Makefile.in.
USES+=		autoreconf:build cpe perl5 shebangfix tar:xz
SHEBANG_FILES=	contrib/randomtrain.sh contrib/scramble.sh \
		src/tests/unsort.pl contrib/*.pl
USE_PERL5=	run
GNU_CONFIGURE=	yes

CPE_VENDOR=	bogofilter_project

UNICODE_USES=	iconv
UNICODE_CONFIGURE_ENABLE=	unicode
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_OFF=	--with-included-gsl

PORTDOCS=	*

TEST_TARGET=	check

.include <bsd.port.pre.mk>

BF_LIBS?=		-l${BDB_LIB_NAME}
BF_CPPFLAGS?=		-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
.if ${PORT_OPTIONS:MUNICODE}
BF_LIBS+=		${ICONV_LIB}
.endif
CPPFLAGS+=	${BF_CPPFLAGS}
LIBS+=		-L${LOCALBASE}/lib ${BF_LIBS}
CONFIGURE_ENV+=	PERL="${PERL}"
INSTALL_TARGET=	install-strip prefix=${PREFIX} mandir=${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's/INTEGRITY_TESTS = t.lock1 t.lock3 t.valgrind/INTEGRITY_TESTS = t.lock1/' \
		-e 's/ENVIRON_TESTS = t.abort/ENVIRON_TESTS =/' \
		${WRKSRC}/src/tests/Makefile.am

post-build:
	cd ${WRKSRC}/src && ${SETENV} SHELL=${SH} ${MAKE_CMD} ${TEST_TARGET} ${_MAKE_JOBS} SHELL=${SH} \
		|| { r=$$? ; head -n30000 ${WRKSRC}/src/tests/test-suite.log ; exit $$r ; }

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
.for i in html programmer xml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.for i in AUTHORS COPYING INSTALL NEWS README README.git \
	doc/README.validation TODO GETTING.STARTED \
	RELEASE.NOTES doc/README.db doc/README.sqlite \
	doc/integrating-with-postfix doc/integrating-with-qmail \
	doc/bogofilter-tuning.HOWTO.html doc/bogofilter-SA-* \
	doc/bogofilter-faq.html doc/bogofilter-faq-fr.html
	  ${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in README.randomtrain README.contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${STAGEDIR}${DOCSDIR}/contrib/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/trio/AUTHORS ${STAGEDIR}${DOCSDIR}/AUTHORS.trio
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.xml ${STAGEDIR}${DOCSDIR}/xml
	${INSTALL_DATA} ${WRKSRC}/doc/programmer/README.freebsd ${STAGEDIR}${DOCSDIR}/programmer
	${INSTALL_PROGRAM} ${WRKSRC}/bogogrep ${STAGEDIR}${PREFIX}/bin/
.for i in bfproxy.pl bogofilter-milter.pl bogo.R bogofilter-qfe.sh \
		mime.get.rfc822.pl parmtest.sh printmaildir.pl \
		bogominitrain.pl \
		randomtrain.sh scramble.sh spamitarium.pl stripsearch.pl trainbogo.sh
	  ${INSTALL_SCRIPT} ${WRKSRC}/contrib/${i} ${STAGEDIR}${DOCSDIR}/contrib/${i}
.endfor
.for i in dot-qmail-bogofilter-default \
	mailfilter.example procmailrc.example vm-bogofilter.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${STAGEDIR}${DOCSDIR}/contrib/${i}
.endfor

.include <bsd.port.post.mk>
