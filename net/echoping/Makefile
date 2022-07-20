PORTNAME=	echoping
PORTVERSION=	6.0.2
PORTREVISION=	9
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ping-like program that uses TCP and/or HTTP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libidn.so:dns/libidn

USES=		autoreconf cpe libtool pkgconfig ssl

CPE_VENDOR=	echoping_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE} \
		--enable-plugin="${PING_PLUGINS}"
INSTALL_TARGET=	install-strip

PING_PLUGINS=	dns random whois

USE_GITLAB=	yes
GL_SITE=	https://framagit.org
GL_ACCOUNT=	bortzmeyer
GL_COMMIT=	ccf3c95d9249d3065db3853486f41c852d20101e
WRKSRC_SUBDIR=	SRC

OPTIONS_DEFINE=	LDAP PGSQL
OPTIONS_DEFAULT=LDAP
OPTIONS_SUB=	yes

LDAP_USE=	OPENLDAP=yes
LDAP_VARS=	PING_PLUGINS+=ldap

PGSQL_USES=	pgsql
PGSQL_VARS=	PING_PLUGINS+=postgresql

pre-configure:
	${FIND} ${WRKSRC} -name configure.ac -execdir ${SH} -c '\
	  ${CAT} ${WRKSRC}/configure-common.ac > configure.ac.tmp && \
	  ${SED} '/configure-common\.ac/d' configure.ac >> configure.ac.tmp && \
	  ${MV} configure.ac.tmp configure.ac' \;
	${REINPLACE_CMD} '/^echoping_LDADD =/s/$$/ -lm/' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
