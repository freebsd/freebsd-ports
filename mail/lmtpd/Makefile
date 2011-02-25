# New ports collection makefile for:	lmtpd
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	lmtpd
PORTVERSION=	0.10.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.oav.net/pll/ SF/pll/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	LMTP server compliant with RFC 2033 and Maildir++

LIB_DEPENDS=	home.1:${PORTSDIR}/misc/libhome

USE_ICONV=	yes

OPTIONS=	PCRE "Support for PCRE" on
OPTIONS+=	MYSQL "Support for MySQL Queries and Logs" on
OPTIONS+=	BDB "Support for Berkeley DB" on
OPTIONS+=	TRE "Support for TRE regexp (Approx regexp)" on
OPTIONS+=	SIEVE "Support for SIEVE regexp (Approx regexp)" on

.include <bsd.port.pre.mk>

.if defined(LMTPD_WITH_BDB_VER)
WITH_BDB_VER=	${LMTPD_WITH_BDB_VER}
.endif

.for num in 3 4
.if defined(WITH_DB${num})
WITH_BDB=	yes
IGNORE=	use 'make config' to select Berkeley DB
OBSOLETE_BDB_VAR+=	WITH_DB${num}
.endif
.endfor

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if defined(WITH_TRE)
LIB_DEPENDS+=	tre:${PORTSDIR}/textproc/libtre/
CONFIGURE_ARGS+=	--with-tre
.else
CONFIGURE_ARGS+=	--without-tre
.endif

.if defined(WITH_SIEVE)
CONFIGURE_ARGS+=	--with-sieve-regex
.else
CONFIGURE_ARGS+=	--without-sieve-regex
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/include/mysql --with-mysqllog
.else
CONFIGURE_ARGS+=	--without-mysql --without-mysqllog
.endif

.if defined(WITH_BDB)
USE_BDB=		yes
WITH_BDB_VER?=		4
INVALID_BDB_VER=	2

.if ${WITH_BDB_VER} == 3
CONFIGURE_ARGS+=	--with-db3=${BDB_INCLUDE_DIR} \
			--without-db4
.else
CONFIGURE_ARGS+=	--with-db4=${BDB_INCLUDE_DIR} \
			--without-db3
.endif
LDFLAGS+=		-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=	--with-db-lib=${BDB_LIB_DIR}
.else
CONFIGURE_ARGS+=	--without-db3 --without-db4
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--without-perl

MAN8=		lmtpd.8
DOCS=		NEWS README TODO

post-patch:
.if defined(WITH_BDB)
	@if [ ! "${BDB_LIB_NAME}" = "db3" ] ; then \
		${REINPLACE_CMD}-e 's;in db4;in ${BDB_LIB_NAME};g' \
			${WRKSRC}/configure ; \
	fi
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/lmtpd.conf \
		${PREFIX}/etc/lmtpd.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/lmtpdlogsum/lmtpdlogsum.pl \
		${PREFIX}/bin/lmtpdlogsum
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/msg
	${INSTALL_DATA} ${WRKSRC}/sql/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/txt/* ${EXAMPLESDIR}/msg
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	${FIND} ${PREFIX}/share/nls -type d -name 'fr_*8859*' ! -name fr_FR.ISO_8859-1 -exec basename {} \; | ${XARGS} -n1 -I % ${ECHO_MSG} share/nls/%/filtercheck.cat >> ${TMPPLIST}
	${FIND} ${PREFIX}/share/nls -type d -name 'fr_*.UTF-8' ! -name fr_FR.UTF-8 -exec basename {} \; | ${XARGS} -n1 -I % ${ECHO_MSG} share/nls/%/filtercheck.cat >> ${TMPPLIST}
	${FIND} ${PREFIX}/share/nls -type d -name 'en_*' -exec basename {} \; | ${XARGS} -n1 -I % ${ECHO_MSG} share/nls/%/filtercheck.cat >> ${TMPPLIST}
	${FIND} ${PREFIX}/share/nls -type d -name 'fr_*8859*' -exec basename {} \; | ${XARGS} -n1 -I _ -R 2 ${ECHO_MSG} "@unexec if ! grep -q _ ${MTREE_FILE} ; then rmdir %D/share/nls/_ >/dev/null || true ; fi" >> ${TMPPLIST}
	${FIND} ${PREFIX}/share/nls -type d -name 'fr_*.UTF-8' -exec basename {} \; | ${XARGS} -n1 -I _ -R 2 ${ECHO_MSG} "@unexec if ! grep -q _ ${MTREE_FILE} ; then rmdir %D/share/nls/_ >/dev/null || true ; fi" >> ${TMPPLIST}
	${FIND} ${PREFIX}/share/nls -type d -name 'en*' -exec basename {} \; | ${XARGS} -n1 -I _ -R 2 echo "@unexec if ! grep -q _ ${MTREE_FILE} ; then rmdir %D/share/nls/_ >/dev/null || true ; fi" >> ${TMPPLIST}

.include <bsd.port.post.mk>
