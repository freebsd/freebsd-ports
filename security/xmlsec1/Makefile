# Ports collection makefile for:	xmlsec1
# Date created:			Apr 17, 2003
# Whom:				Jim Geovedi <jim@corebsd.or.id>
#
# $FreeBSD$
#

PORTNAME=	xmlsec1
PORTVERSION=	1.2.4
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	XML Security Library

RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_OPENSSL=	yes
USE_GNOME=	gnomehack lthack libxslt gnometarget
USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
PLIST_FILES=	bin/xmlsec1 bin/xmlsec1-config etc/xmlsec1Conf.sh

MAN1=	xmlsec1.1 xmlsec1-config.1

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-gnutls="${LOCALBASE}"
LIB_DEPENDS+=		gnutls.12:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOCS=docs
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_GNUTLS=yes   Enable GNUTLS support"
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e 's|src apps man docs|src apps man \$${DOCS}|g ; \
		 s|^confexecdir =.*$$|confexecdir = \$$(sysconfdir)|g' \
			${WRKSRC}/Makefile.in

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

.include <bsd.port.mk>
