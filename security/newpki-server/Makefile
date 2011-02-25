# New ports collection makefile for:	newpki-lib
# Date created:		2005-07-05
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	newpki-server
DISTVERSION=	2.0.0-beta4
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/newpki/${PORTNAME}/2.0.0-beta4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ PKI server from newpki project

LIB_DEPENDS=	newpki.2:${PORTSDIR}/security/newpki-lib

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0.0

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_MYSQL=	yes
USE_OPENLDAP=	yes
MANCOMPRESSED=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DLDAP_DEPRECATED" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-newpki-include=${LOCALBASE}/include/newpki \
			--with-newpki-lib=${LOCALBASE}/lib \
			--with-mysql-lib=${LOCALBASE}/lib/mysql \
			--with-libiconv-prefix=${LOCALBASE} \
			--program-transform-name=

MAN1=	newpki-server.1

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700019
BROKEN=		does not compile with OpenSSL 0.9.8b
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure \
		${WRKSRC}/publication/ldap/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/config.conf ${PREFIX}/etc/newpki.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/newpki-server.1.gz ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
