# Created by: Abel Chow <achow@transoft.net>
# $FreeBSD$

PORTNAME?=	tidy
DISTVERSION=	090315-cvs
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	LOCAL/thierry
#MASTER_SITES=	http://tidy.sourceforge.net/src/%SUBDIR%/	\
#		http://tidy.sourceforge.net/docs/:docs
#MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX?=	-devel

MAINTAINER?=	thierry@FreeBSD.org
COMMENT?=	Utility to clean up and pretty print HTML/XHTML/XML

BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		tar:bzip2

SLAVEDIRS=	www/tidy-lib
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

.if !defined(WITH_SHLIB)
USES+=		gmake
PLIST_SUB=	SHLIB="@comment " NSHLIB=""
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}
CONFLICTS=	tidy-20000804* tidy-lib-[0-9]*
.else
USES+=		autoreconf libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	SHLIB="" NSHLIB="@comment "
CONFLICTS=	tidy-devel-[0-9]*
.endif

DESCR=		${.CURDIR}/pkg-descr

BIN2STRIP=	tidy tab2space

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
. if !defined(WITH_SHLIB)
ALL_TARGET=	all doc
DOCFILES=	quickref.html
. endif
DOCFILES+=	Overview.html checked_by_tidy.gif faq.html grid.gif pending.html	\
		release-notes.html tidy.css tidy.gif
.endif

.if defined(MAINTAINER_MODE)

CVSROOT=	":pserver:anonymous@tidy.cvs.sourceforge.net:/cvsroot/tidy"
CVS_PASSFILE=	${WRKDIR}/temp-cvs-passfile

getcvs:
	${MKDIR} ${WRKDIR}/cvs
	${ECHO_CMD} ${CVSROOT} A > ${CVS_PASSFILE}
	cd ${WRKDIR}/cvs &&	\
	CVSROOT=${CVSROOT} CVS_PASSFILE=${CVS_PASSFILE} cvs -z3 co -P tidy

tarball:
	${RM} -rf ${WRKDIR}/cvs/tidy/CVSROOT
	${FIND} ${WRKDIR}/cvs -name CVS | ${XARGS} ${RM} -rf
	cd ${WRKDIR}/cvs &&	\
	${TAR} cfj ${_DISTDIR}${DISTFILES} tidy

.endif

post-patch:
	${CHMOD} a+x ${WRKSRC}/test/testxml.sh
.if !defined(WITH_SHLIB)
	${CP} ${WRKSRC}/build/gmake/Makefile ${WRKSRC}
.else
	${CP} -R -f ${WRKSRC}/build/gnuauto/* ${WRKSRC}
. for t in testone.sh testaccessone.sh
	${REINPLACE_CMD} -e 's|../bin/tidy|../console/tidy|'	\
		${WRKSRC}/test/${t}
. endfor
.endif

post-install:
.for pgm in ${BIN2STRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${pgm}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/htmldoc/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

regression-test:
.for t in testaccess.sh testall.sh testxml.sh
	cd ${WRKSRC}/test && ./${t}
.endfor

.include <bsd.port.mk>
