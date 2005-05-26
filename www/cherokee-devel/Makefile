# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	0.4.23
CATEGORIES=	www
MASTER_SITES=	http://www.0x50.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extremely fast and flexible web server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-wwwroot=${PREFIX}/www
INSTALLS_SHLIB=	yes

MAN1=		cget.1 cherokee-config.1 cherokee.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_GNUTLS)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-tls=openssl
LDFLAGS+=	-lssl -lcrypto
.else
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-tls=gnutls
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PLIST_SUB+=	PAM="" PAM5="@comment "
.else
PLIST_SUB+=	PAM="@comment " PAM5=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/sherokee_reinplace|true|g' \
		${WRKSRC}/Makefile.in

pre-build:
.for file in advanced.conf cherokee.conf mods-ssl sites-default sites-example
	@cd ${BUILD_WRKSRC} && ${SED} -e \
		's:%sysconfdir%:${PREFIX}/etc:g ; \
		 s:%datadir%:${PREFIX}/share:g ; \
		 s:%wwwroot%:${PREFIX}/www:g ; \
		 s:%prefix%:${PREFIX}:g' < ${file}.sample.pre > ${file}.sample
.endfor

pre-install:
	@if [ ! -f ${PREFIX}/www ]; then \
		${MKDIR} ${PREFIX}/www;\
	fi
	@if [ ! -f ${PREFIX}/www/data ] ; then \
		${MKDIR} ${PREFIX}/www/data;\
	fi
	@${ECHO_MSG} " `pwd` "

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/Intro.txt ${DATADIR}
	@${ECHO_MSG} " "
	@${ECHO_MSG} " Dont forget to read the doc "
	@${ECHO_MSG} " ${PREFIX}/share/cherokee/Intro.txt"
	@${ECHO_MSG} " "

.include <bsd.port.post.mk>
