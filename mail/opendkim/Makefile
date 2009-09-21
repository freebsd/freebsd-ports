# New ports collection makefile for:	opendkim
# Date created:		2009-08-26
# Whom:			Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	opendkim
PORTVERSION=	1.0.0
CATEGORIES=	mail security
MASTER_SITES=	SF/opendkim

MAINTAINER=	umq@ueo.co.jp
COMMENT=	DKIM milter implimentation

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	milter-opendkim
USE_LDCONFIG=	yes

MAN_COMPRESSED=	no
MAN3=		ar.3
MAN5=		opendkim.conf.5
MAN8=		opendkim-genkey.8 opendkim-testadsp.8 \
		opendkim-testkey.8 opendkim.8
PORTDOCS0=	FEATURES INSTALL KNOWNBUGS LICENSE LICENSE.Sendmail \
		README RELEASE_NOTES RELEASE_NOTES.Sendmail
PORTDOCS=	docs/*

.include <bsd.port.pre.mk>

WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}

.if ${OSVERSION} < 700000
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}

.include "${.CURDIR}/Makefile.features"

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if (defined(WITH_POPAUTH) \
	|| defined(WITH_QUERY_CACHE) \
	|| defined(WITH_BODYLENGTH_DB) \
	|| defined(WITH_STATS)) \
	&& !defined(WITH_BDB_BASE)
#BROKEN=		LIBDB_INCDIR nor LIBDB_LIBDIRS cannot be set individually
CONFIGURE_ARGS+=	--with-db
USE_BDB=	41+
.endif
.if defined(WITH_UNBOUND) && !defined(WITHOUT_UNBOUND)
BROKEN=		configure fails since arlib cannot be disabled
.if defined(WITH_ARLIB)
IGNORE=		libar cannot be used simultaneously with libunbound
.endif
CONFIGURE_ARGS+=	--with-unbound \
			--disable-arlib
LIB_DEPENDS+=	unbound:${PORTSDIR}/dns/unbound
PLIST_SUB+=		ARLIB="@comment "
.else
.if !defined(WITHOUT_ARLIB)
PLIST_SUB+=		ARLIB=""
CONFIGURE_ARGS+=	--enable-arlib
.else
CONFIGURE_ARGS+=	--disable-arlib
PLIST_SUB+=		ARLIB="@comment "
.endif
.endif
.if defined(WITH_POPAUTH) && !defined(WITHOUT_POPAUTH)
CONFIGURE_ARGS+=	--enable-popauth
.endif
.if defined(WITH_QUERY_CACHE) && !defined(WITHOUT_QUERY_CACHE)
CONFIGURE_ARGS+=	--enable-querycache
.endif

post-extract:
.for f in ${PORTDOCS0}
	@${CP} ${WRKSRC}/${f} ${WRKSRC}/docs/
.endfor

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/sbin/opendkim
.endif
	@${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample ${PREFIX}/etc/mail/
.if !defined(NOPORTDOCS)
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
