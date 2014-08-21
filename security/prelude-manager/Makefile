# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/243/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libprelude.so:${PORTSDIR}/security/libprelude \
		libpreludedb.so:${PORTSDIR}/security/libpreludedb \
		libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit

USES=		pkgconfig gettext iconv gmake
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	prelude-manager

CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USERS?=		prelude
GROUPS?=	prelude

MAN1=		prelude-manager.1

PLIST_SUB=	PRELUDEUSER=${USERS} \
		PRELUDEGROUP=${GROUPS}

OPTIONS_DEFINE=	XML
OPTIONS_DEFAULT=XML

XML_DESC=	XML plugin

NO_STAGE=	yes
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
