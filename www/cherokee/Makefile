# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/${PORTVERSION:R}/${PORTVERSION}/ \
		CENKES http://www.alaskaparadise.com/freebsd/

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	An extremely fast and flexible web server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS=	cherokee-devel-[0-9]*
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	cherokee.sh
USE_GCC=	3.4+
USE_BISON=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man \
		--with-wwwroot=${PREFIX}/www \
		--disable-static

OPTIONS=	GNUTLS	"TLS/SSL Use gnutls"	on \
		OPENSSL	"TLS/SSL Use openssl"	off \
		NOTLS	"No TLS/SSL"		off \
		NOIPV6	"No IPv6"		off

MAN1=		cget.1 cherokee-config.1 cherokee.1 cherokee_logrotate.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-tls=gnutls
.endif

.if defined(WITH_OPENSSL)
CFLAGS+=	-DHAVE_OPENSSL
CONFIGURE_ARGS+=--enable-tls=openssl
LDFLAGS+=	-lssl -lcrypto
.endif

.if defined(WITH_NOTLS)
CONFIGURE_ARGS+=--disable-tls
.endif

.if defined(WITH_NOIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@mkdir_p@|${MKDIR} --|g'

pre-build:
.for file in advanced.conf cherokee.conf mods-ssl sites-default sites-example
	@cd ${BUILD_WRKSRC} && ${SED} -e \
		's:%sysconfdir%:${PREFIX}/etc:g ; \
		 s:%datadir%:${PREFIX}/share:g ; \
		 s:%wwwroot%:${PREFIX}/www:g ; \
		 s:%prefix%:${PREFIX}:g' < ${file}.sample.pre > ${file}.sample
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/develop/Intro.txt ${DATADIR}/
	@${ECHO_MSG} " "
	@${ECHO_MSG} " Dont forget to read the doc "
	@${ECHO_MSG} " ${PREFIX}/share/cherokee/Intro.txt"
	@${ECHO_MSG} " "

.include <bsd.port.post.mk>
