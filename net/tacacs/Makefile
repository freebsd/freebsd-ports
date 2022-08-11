PORTNAME=	tacacs
PORTVERSION=	202206071936
CATEGORIES=	net
MASTER_SITES=	https://www.pro-bono-publico.de/projects/src/

MAINTAINER=	akuz84@gmail.com
COMMENT=	TACACS+ daemon from pro-bono

LICENSE=	BSD3CLAUSE

USES=		gmake perl5 shebangfix ssl tar:bzip2

USE_LDCONFIG=	yes

USE_RC_SUBR?=	tac_plus

SHEBANG_FILES=	tac_plus/sample/tac_plus.cfg

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--installroot=${STAGEDIR} \
		--libdir=${LOCALBASE}/lib \
		--with-ssl \
		--with-zlib \
		mavis \
		mavisd \
		spawnd \
		tac_plus

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	tac_plus4

WRKSRC=		${WRKDIR}/PROJECTS

USERS=		tacacs
GROUPS=		tacacs

OPTIONS_DEFINE=		CURL FREERADIUS PCRE SCTP
OPTIONS_DEFAULT=	SCTP

CURL_DESC=		Curl support
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--with-curl-lib=${LOCALBASE}/lib
CURL_CONFIGURE_OFF=

FREERADIUS_DESC=		Freeradius support
FREERADIUS_LIB_DEPENDS=		libfreeradius-radius.so:net/freeradius3
FREERADIUS_CONFIGURE_ON=	--with-pcre-lib=${LOCALBASE}/lib
FREERADIUS_CONFIGURE_OFF=

PCRE_DESC=		PCRE support
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ON=	--with-pcre-lib=${LOCALBASE}/lib
PCRE_CONFIGURE_OFF=

SCTP_DESC=		SCTP support
SCTP_CONFIGURE_WITH=	sctp

post-build:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/tac_plus/sample/tac_plus.cfg

post-install:

.include <bsd.port.mk>
