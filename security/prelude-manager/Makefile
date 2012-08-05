# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.9.14.2
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=   http://www.prelude-technologies.com/download/releases/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=	prelude.20:${PORTSDIR}/security/libprelude \
		gnutls.47:${PORTSDIR}/security/gnutls

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
USE_RC_SUBR=	prelude-manager
CONFIGURE_ARGS=		--with-html-dir=${PREFIX}/share/doc \
			--localstatedir=/var
CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include

USERS?=		prelude
GROUPS?=	prelude

MAN1=		prelude-manager.1

PLIST_SUB=	PRELUDEUSER=${USERS} \
		PRELUDEGROUP=${GROUPS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_XML)
PLIST_SUB+=		WITH_XML="@comment "
CONFIGURE_ARGS+=	--disable-xmltest --without-xml
.else
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	WITH_XML=""
.endif

.if defined(WITHOUT_PRELUDEDB)
PLIST_SUB+=	WITH_PRELUDEDB="@comment "
.else
LIB_DEPENDS+=	preludedb.4:${PORTSDIR}/security/libpreludedb
PLIST_SUB+=	WITH_PRELUDEDB=""
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prelude-manager/prelude-manager.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-manager/prelude-manager.conf-dist \
	      ${PREFIX}/etc/prelude-manager/prelude-manager.conf ; \
	fi
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/smtp
	${INSTALL_DATA} ${WRKSRC}/plugins/reports/smtp/template.example ${EXAMPLESDIR}/smtp/template.example
.endif

.include <bsd.port.post.mk>
