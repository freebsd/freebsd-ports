# New ports collection makefile for:	libspf
# Date created:		28 February 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	libspf
PORTVERSION=	0.25.b
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf.org/files/
DISTNAME=	${PORTNAME}.${PORTVERSION}eta

DEPRECATED=	"stale, try mail/libspf2"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sender Policy Framework (SPF) library and client

NOT_FOR_ARCHS=	amd64 alpha

USE_GETOPT_LONG=yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.25
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
LIBSPF_REV=	1
PLIST_SUB=	PORTNAME=${PORTNAME} LIBSPF_REV=${LIBSPF_REV}
LDFLAGS+=	-L${WRKSRC}

# Supported tunables:
#
# WITH_SPF_LOG_FILE=/foo/bar	enable transaction logfile (if unset: no log)
# WITH_SPF_DEBUG=yes		enable debugging
# WITH_SPF_DEBUG_FILE=/foo/baz	enable debug logfile (if unset: stdout/stderr)

.if defined(WITH_SPF_LOG_FILE)
SPF_LOG_FILE=	${WITH_SPF_LOG_FILE}
.else
SPF_LOG_FILE=	/dev/null
.endif

.if defined(WITH_SPF_DEBUG)
SPF_CFLAGS=	-ggdb -DDEBUG -D_SPF_DEBUG
.if defined(WITH_SPF_DEBUG_FILE)
SPF_CFLAGS+=	-D_SPF_DEBUG_LOGFILE
.endif
.endif

.if defined(WITH_SPF_DEBUG_FILE)
SPF_DEBUG_FILE=	${WITH_SPF_DEBUG_FILE}
.else
SPF_DEBUG_FILE=	/dev/null
.endif

SPF_CFLAGS+=	-DDEBUG_LOG_FILE=\\\"${SPF_DEBUG_FILE}\\\" \
		-DOUTPUT_LOG_FILE=\\\"${SPF_LOG_FILE}\\\"

# This is all a bit messy, but given the inconvenient original Makefile,
# this seems to be the best way to make this port work in this version.
# The author of libspf is working on autotools support, so this ugliness
# should have an end soon.
post-patch:
	@${REINPLACE_CMD} \
	    -e 's,^CFLAGS:=.*,CFLAGS+=-Wall -D_BSD_SOURCE ${SPF_CFLAGS},' \
	    -e 's/^CPPFLAGS:=/#CPPFLAGS:=/' \
	    -e 's/^LDFLAGS:=/#LDFLAGS:=/' \
	    -e 's/make /${GMAKE} /g' \
	    -e 's/-lresolv//g' \
	    -e 's/libspf.a : -lc/libspf.a :/g' \
	    -e 's/libspf\.so\.1\.0\.1/libspf.so.${LIBSPF_REV}/g' \
	    -e 's/-soname,libspf\.so\.1/-soname,libspf.so.${LIBSPF_REV}/g' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
	    -e 's,^CFLAGS:=,CFLAGS:=${CFLAGS} ${CPPFLAGS},' \
	    -e 's,^CPPFLAGS:=,CPPFLAGS:=${CPPFLAGS},' \
	    -e 's,^LDFLAGS:=.*,LDFLAGS=${LDFLAGS},' \
	    -e 's/make /${GMAKE} /g' \
	    -e 's/-o spfquery/-o spfquery-${PORTNAME}/g' \
	    ${WRKSRC}/tools/Makefile
	@${REINPLACE_CMD} \
	    -e 's/#include "error.h"//' \
	    ${WRKSRC}/main.c ${WRKSRC}/dns.c
	@${REINPLACE_CMD} \
	    -e 's,\(#define DEBUG_LOG_FILE.*\),/* \1 */,' \
	    -e 's,\(#define OUTPUT_LOG_FILE.*\),/* \1 */,' \
	    ${WRKSRC}/util.h
	@${REINPLACE_CMD} \
	    -e 's/spfquery /spfquery-${PORTNAME} /' \
	    -e 's/getopt_long_only/getopt_long/g' \
	    -E -e '/stderr/s/ -([a-z]{2,})/ --\1/g' \
	    ${WRKSRC}/tools/spfquery.c

post-build:
	@(cd ${WRKSRC}/tools; ${SETENV} ${MAKE_ENV} ${GMAKE} shared )

do-install:
	${INSTALL_DATA} ${WRKSRC}/spf.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libspf.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libspf.so.${LIBSPF_REV} ${PREFIX}/lib
	(cd ${PREFIX}/lib ; ${LN} -sf libspf.so.${LIBSPF_REV} libspf.so)
	${INSTALL_PROGRAM} ${WRKSRC}/tools/spfquery-${PORTNAME} ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
