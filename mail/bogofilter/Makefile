PORTNAME=	bogofilter
DISTVERSION=	1.3.0.rc1
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	SF/bogofilter/bogofilter-current/bogofilter-1.3.0.beta/ \
		https://gitlab.com/-/project/12408342/uploads/647db3bd2f28a1f91bdd3bb1945d91fe/
PKGNAMESUFFIX?=	# blank by default, and ?= so slave ports can override

MAINTAINER?=	mandree@FreeBSD.org
COMMENT?=	Fast, teachable, learning spam detector (LMDB database)
WWW=		https://bogofilter.sourceforge.io/

LICENSE=	GPLv2

OPTIONS_DEFINE=		GSL UNICODE DOCS
OPTIONS_DEFAULT=	GSL UNICODE
GSL_DESC=		Link with system-wide GSL dynamically (recommended)
UNICODE_DESC=		Normalize tokens to Unicode (UTF-8) (recommended)

CONFLICTS_INSTALL?=	bogofilter-bdb bogofilter-kc bogofilter-lmdb bogofilter-sqlite  # bogofilter-bdb and -lmdb are historic, but let's keep them for a while

USES+=		cpe perl5 shebangfix tar:xz
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

BF_CPPFLAGS?=		-I${LOCALBASE}/include
BF_LIBS?=		# empty, can be passed in by slave ports
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
.if !defined(MASTERDIR) || ${MASTERDIR} == ${.CURDIR}
CONFIGURE_ARGS+=	--with-database=lmdb
LIB_DEPENDS=   liblmdb.so:databases/lmdb
.endif
.if ${PORT_OPTIONS:MUNICODE}
BF_LIBS+=		${ICONV_LIB}
.endif
CPPFLAGS+=	${BF_CPPFLAGS}
LIBS+=		-L${LOCALBASE}/lib ${BF_LIBS}
CONFIGURE_ENV+=	PERL="${PERL}"
INSTALL_TARGET=	install-strip prefix=${PREFIX} mandir=${PREFIX}/share/man

post-patch:
	${REINPLACE_CMD} -e 's/INTEGRITY_TESTS = t.lock1 t.lock3 t.valgrind/INTEGRITY_TESTS = t.lock1/' \
		-e 's/ENVIRON_TESTS = t.abort/ENVIRON_TESTS =/' \
		${WRKSRC}/src/tests/Makefile.in

post-build:
	cd ${WRKSRC}/src && ${SETENVI} SHELL=${SH} ${MAKE_CMD} ${TEST_TARGET} ${_MAKE_JOBS} SHELL=${SH} \
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
	mailfilter.example vm-bogofilter.el
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${STAGEDIR}${DOCSDIR}/contrib/${i}
.endfor

.include <bsd.port.post.mk>
