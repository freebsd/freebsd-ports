# New ports collection makefile for:	polymake
# Date created:				21 December 2004
# Whom:					Ewgenij Gawrilow <gawrilow@math.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	polymake
PORTVERSION=	2.9.9
CATEGORIES=	math java
MASTER_SITES=	http://wwwopt.mathematik.tu-darmstadt.de/polymake/lib/exe/fetch.php/download/

MAINTAINER=	gawrilow@math.tu-berlin.de
COMMENT=	A framework for experimental discrete geometry

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		${LOCALBASE}/share/xml/dtd/xhtml/xhtml-lat1.ent:${PORTSDIR}/textproc/xhtml
RUN_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		${LOCALBASE}/share/xml/dtd/xhtml/xhtml-lat1.ent:${PORTSDIR}/textproc/xhtml \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-XML-LibXSLT>=0:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${LOCALBASE}/bin/c++filt:${PORTSDIR}/devel/binutils
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		readline.[56]:${PORTSDIR}/devel/readline

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GCC=	4.2+
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.6

MAKE_ENV+=	ProcessDep=none
NO_INSTALL_MANPAGES=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME}
CONFIGURE_ARGS+=	--prefix='${PREFIX}' --datadir='${DATADIR}' \
			--libdir='${PREFIX}/libexec/polymake' \
			--docdir='${DOCSDIR}' --without-prereq \
			LDFLAGS='-L${PREFIX}/lib'

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
IGNORE=		does not build with Perl 5.14+
.endif

pre-fetch:
	@if [ ${MAKE_JOBS_NUMBER} -gt 1 ]; then \
		${ECHO_CMD} "Building this port uses a lot of CPU power, and a lot of memory to the point"; \
		${ECHO_CMD} "that swap space might be used extensively.  Consider using less threads, as"; \
		${ECHO_CMD} "this might cause the build to be considerably faster.  Currently the build is"; \
		${ECHO_CMD} "set to use ${MAKE_JOBS_NUMBER} threads.  To change to <n> threads, use"; \
		${ECHO_CMD}; \
		${ECHO_CMD} "make MAKE_JOBS_NUMBER=<n>"; \
	fi

post-install:
	${INSTALL_DATA} ${PREFIX}/libexec/polymake/conf.make ${PREFIX}/libexec/polymake/conf.make.in
.if !defined(NOPORTDOCS)
	${SETENV} POLYMAKE_USER_DIR=${WRKDIR}/.polymake-tmp ${GMAKE} -C ${WRKSRC} docs
.endif
# Don't use PLIST_SUBS here, as perl might not be installed early enough.
	@${PERL} -i -pe 'BEGIN{use Config;} s/%%PERL_REAL_ARCH%%/$$Config{archname}/e' ${TMPPLIST}

.include <bsd.port.post.mk>
