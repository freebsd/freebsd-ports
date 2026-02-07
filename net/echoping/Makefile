PORTNAME=	echoping
PORTVERSION=	6.0.2
PORTREVISION=	13
CATEGORIES=	net

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Ping-like program that uses TCP and/or HTTP
WWW=		https://framagit.org/bortzmeyer/echoping

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		autoreconf cpe iconv libtool pkgconfig ssl

CPE_VENDOR=	echoping_project
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos \
		--with-popt=${LOCALBASE} \
		--enable-plugin="${PING_PLUGINS}"
INSTALL_TARGET=	install-strip

PING_PLUGINS=	dns random whois

USE_GITLAB=	yes
GL_SITE=	https://framagit.org
GL_ACCOUNT=	bortzmeyer
GL_TAGNAME=	ccf3c95d9249d3065db3853486f41c852d20101e
WRKSRC_SUBDIR=	SRC

OPTIONS_DEFINE=	LDAP PGSQL
OPTIONS_DEFAULT=LDAP IDN
OPTIONS_SINGLE=	LIBIDN
OPTIONS_SINGLE_LIBIDN=IDN IDN2
OPTIONS_SUB=	yes

IDN_DESC=	Use GNU libidn
IDN2_DESC=	Use GNU libidn2

LDAP_USES=	ldap
LDAP_VARS=	PING_PLUGINS+=ldap

PGSQL_USES=	pgsql
PGSQL_VARS=	PING_PLUGINS+=postgresql

pre-configure:
	${FIND} ${WRKSRC} -name configure.ac -execdir ${SH} -c '\
	  ${CAT} ${WRKSRC}/configure-common.ac > configure.ac.tmp && \
	  ${SED} '/configure-common\.ac/d' configure.ac >> configure.ac.tmp && \
	  ${MV} configure.ac.tmp configure.ac' \;
	${REINPLACE_CMD} '/^echoping_LDADD =/s/$$/ -lm/' ${WRKSRC}/Makefile.am

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN2}
CONFIGURE_ARGS+=	--with-libidn2=${LOCALBASE}
LIB_DEPENDS+=		libidn2.so:dns/libidn2
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-idn2-acinclude.m4 \
			${PATCHDIR}/extra-patch-idn2-configure.ac \
			${PATCHDIR}/extra-patch-idn2-echoping.c \
			${PATCHDIR}/extra-patch-idn2-echoping.h
.else
CONFIGURE_ARGS+=	--with-libidn=${LOCALBASE}
LIB_DEPENDS+=		libidn.so:dns/libidn
.endif

.include <bsd.port.mk>
