# Ports collection makefile for:	xmlsec1
# Date created:			Apr 17, 2003
# Whom:				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	xmlsec1
PORTVERSION=	1.2.9
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	XML Security Library

RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
BUILD_DEPENDS=	${RUN_DEPENDS}

OPTIONS=	GNUTLS	"Enable GNUTLS support"	off	\
		NSS	"Enable Mozilla's NSS support"	off

USE_OPENSSL=	yes
OPENSSL_CFLAGS+=-DXMLSEC_OPENSSL_097=1 -DXMLSEC_CRYPTO_OPENSSL=1
USE_GNOME=	gnomehack lthack libxslt gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	bin/xmlsec1 bin/xmlsec1-config etc/xmlsec1Conf.sh

MAN1=	xmlsec1.1 xmlsec1-config.1
# The software comes with its own tests, but it is nauseating to sort,
# which failures are, and which aren't legitimate. Some other day, maybe.
#ALL_TARGET=	all check-all
MAKE_ENV+=	ABS_BUILDDIR=${WRKSRC} TMPFOLDER=${WRKSRC}
MAKE_ARGS+=	-EABS_BUILDDIR

.if !defined(NOPORTDOCS)
MAKE_ENV+=	DOCS=docs
.endif

post-install:
	@${FIND} ${PREFIX}/include/xmlsec1 -type f | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/xmlsec1 -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/libxmlsec1* | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/libdata/pkgconfig/xmlsec1* | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type f | ${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-gnutls="${LOCALBASE}"
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|src apps man docs|src apps man \$${DOCS}|g' \
	    -e 's|^confexecdir =.*$$|confexecdir = \$$(sysconfdir)|g' \
	    -e 's|/tmp/\*\.log|${WRKSRC}/*.log|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl"|"|' \
	    -e 's,with_nspr/include,with_nspr/include/nspr ${PTHREAD_CFLAGS},' \
	    -e 's,with_nss/include,with_nss/include/nss/nss,' \
	    -e 's,\(CPPFLAGS="\$$NSS_CFLAGS\),\1 $$NSPR_CFLAGS,' \
	    -e 's,\(-lplc4\)",\1 ${PTHREAD_LIBS}",' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITH_NSS)
	# Makeing the xmlsec1 executable multi-threaded to let load -lnss,
	# when needed.
	@${REINPLACE_CMD} -e 's,^\(xmlsec1_LDADD = \)\\$$,\1 ${PTHREAD_LIBS}\\,' \
		${WRKSRC}/apps/Makefile.in

CONFIGURE_ARGS+=	--with-nss="${LOCALBASE}" --with-nspr="${LOCALBASE}"
LIB_DEPENDS+=		nss3:${PORTSDIR}/security/nss
.else
CONFIGURE_ARGS+=	--without-nss
.endif

.include <bsd.port.post.mk>
