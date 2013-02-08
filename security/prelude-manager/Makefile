# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/243/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		prelude:${PORTSDIR}/security/libprelude \
		preludedb:${PORTSDIR}/security/libpreludedb \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit

USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

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

OPTIONS_DEFINE=	XML
OPTIONS_DEFAULT=XML

XML_DESC=	XML plugin

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MXML}
PLIST_SUB+=		WITH_XML="@comment "
CONFIGURE_ARGS+=	--disable-xmltest --without-xml
.else
USE_GNOME=	libxml2
PLIST_SUB+=	WITH_XML=""
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prelude-manager/prelude-manager.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude-manager/prelude-manager.conf-dist \
	      ${PREFIX}/etc/prelude-manager/prelude-manager.conf ; \
	fi
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/smtp
	${INSTALL_DATA} ${WRKSRC}/plugins/reports/smtp/template.example \
		${EXAMPLESDIR}/smtp/template.example
.endif

.include <bsd.port.mk>
