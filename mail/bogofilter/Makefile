# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	bogofilter
PORTVERSION=	1.2.4
PORTREVISION?=	5
CATEGORIES?=	mail
MASTER_SITES=	SF/bogofilter/bogofilter-current/bogofilter-${PORTVERSION}

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

CONFLICTS_INSTALL?=	bogofilter-sqlite-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-tc-[0-9]* [a-z][a-z]-bogofilter-[0-9]*

USES+=		cpe perl5 shebangfix tar:bzip2
SHEBANG_FILES=	contrib/randomtrain.sh contrib/scramble.sh \
		src/tests/unsort.pl contrib/*.pl
USE_PERL5=	run
GNU_CONFIGURE=	yes

CPE_VENDOR=	bogofilter_project

UNICODE_USES=	iconv
UNICODE_CONFIGURE_ENABLE=	unicode
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_ARGS_OFF=	--with-included-gsl

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

# XXX: disable self-tests until issue with automake-1.13 is sorted out
# post-build::
# 	cd ${WRKSRC}/src && make check SHELL=${SH}

post-install::
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
.for i in html programmer xml
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.for i in AUTHORS COPYING INSTALL NEWS README README.svn \
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
