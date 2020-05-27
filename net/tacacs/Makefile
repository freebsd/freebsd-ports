# $FreeBSD$

PORTNAME=	tacacs
PORTVERSION=	202004081858
CATEGORIES=	net
MASTER_SITES=	http://www.pro-bono-publico.de/projects/src/

MAINTAINER=	akuz84@gmail.com
COMMENT=	TACACS+ daemon from pro-bono

LICENSE=	BSD3CLAUSE

USES=		gmake perl5 ssl shebangfix

CONFLICTS=	tac_plus4

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-ssl \
		--with-zlib \
		--libdir=${LOCALBASE}/lib \
		--installroot=${STAGEDIR} mavis spawnd mavisd tac_plus

USE_LDCONFIG=			yes

OPTIONS_DEFINE=			CURL FREERADIUS SCTP PCRE
OPTIONS_DEFAULT=		SCTP

MAKE_JOBS_UNSAFE=yes

SCTP_DESC=			SCTP support
SCTP_CONFIGURE_WITH=		sctp

PCRE_DESC=			PCRE support
PCRE_LIB_DEPENDS=		libpcre.so:devel/pcre
PCRE_CONFIGURE_ON=		--with-pcre-lib=${LOCALBASE}/lib
PCRE_CONFIGURE_OFF=

CURL_DESC=			Curl support
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_CONFIGURE_ON=		--with-curl-lib=${LOCALBASE}/lib
CURL_CONFIGURE_OFF=

FREERADIUS_DESC=		Freeradius support
FREERADIUS_LIB_DEPENDS=		libfreeradius-radius.so:net/freeradius3
FREERADIUS_CONFIGURE_ON=	--with-pcre-lib=${LOCALBASE}/lib
FREERADIUS_CONFIGURE_OFF=

USERS=		tacacs
GROUPS=		tacacs

WRKSRC=		${WRKDIR}/PROJECTS

SHEBANG_FILES=	tac_plus/sample/tac_plus.cfg

USE_RC_SUBR?=	tac_plus

post-build:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/tac_plus/sample/tac_plus.cfg

post-install:

.include <bsd.port.mk>
