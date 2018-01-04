# Created by: gahr
# $FreeBSD$

PORTNAME=	deltarpm
PORTVERSION=	3.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.suse.com/pub/projects/deltarpm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that generates delta RPMs

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	librpm.so:archivers/rpm4

USES=		gmake python shebangfix tar:bz2
USE_PYTHON=	flavors optsuffix
SHEBANG_FILES=	drpmsync

ALL_TARGET=	all
MAKE_ARGS+=	prefix=${PREFIX}

post-patch:
	${REINPLACE_CMD} \
	    -e '/prefix=/s|=|?=|' \
	    -e '/^CFLAGS/s|$$| -I${LOCALBASE}/include|' \
	    -e '/^LDFLAGS/s|$$| -L${LOCALBASE}/lib|' \
	    -e '/^PYTHONS/s|= .*$$|= ${PYTHON_CMD}|' \
	    -e 's|make |${MAKE_CMD} |g' \
	    -e 's|-m 755|-m 755 -s|' \
	    -e 's|-s drpmsync|drpmsync|' \
	    ${WRKSRC}/${MAKEFILE}
	${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} \
	    -e 's|off64_t|off_t|g' \
	    -e 's|mkstemp64|mkstemp|g' \
	    -e 's|fopen64|fopen|g' \
	    -e 's|ftello64|ftello|g' \
	    -e 's|pwrite64|pwrite|g' \
	    -e 's|pread64|pread|g' \
	    -e 's|fseeko64|fseeko|g' \
	    -e 's|ftruncate64|ftruncate|g' \
	    -e 's|S_ISLINK|S_ISLNK|g'
	${REINPLACE_CMD} -e '8,11d' ${WRKSRC}/applydeltarpm.c

post-build:
	cd ${WRKSRC} && ${CC} -shared -o _deltarpm.so \
	    readdeltarpm.o rpmhead.o util.o md5.o cfile.o \
	    deltarpmmodule.c \
	    `${PYTHON_CMD}-config --cflags` -fPIC \
	    -lbz2 -lz -llzma

post-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/_deltarpm.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/deltarpm.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
