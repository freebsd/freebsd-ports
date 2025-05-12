PORTNAME=	nmh
PORTVERSION=	${NMH_COMMIT_DATE}
PORTREVISION=	1
MASTER_SITES=	#
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${NMH_COMMIT_DATE}-${GIT_TAGNAME}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Cleaned up MH mailer suite
WWW=		https://savannah.nongnu.org/projects/nmh/

GIT_TAGNAME=	3ba09dd
NMH_COMMIT_DATE=	2025.06.11

WRKSRC=		${WRKDIR}/${PORTNAME}-${GIT_TAGNAME}

LICENSE=	BSD3CLAUSE

USES=		autoreconf:build cpe gmake iconv ncurses readline shebangfix
SHEBANG_FILES=	docs/contrib/ml docs/contrib/replyfilter docs/contrib/vpick
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc \
		--docdir=${DOCSDIR}
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblockfile.so:devel/liblockfile

OPTIONS_DEFINE=	DOCS HASH_BKP SASL2 TLS REPLYFILTER
OPTIONS_RADIO=	MIME_HTML
OPTIONS_SINGLE=	MTS LOCKING
OPTIONS_SINGLE_MTS=	SMTP SENDMAIL_SMTP SENDMAIL_PIPE
OPTIONS_SINGLE_LOCKING=	DOT FCNTL FLOCK LOCKF
OPTIONS_RADIO_MIME_HTML=	ELINKS LINKS LYNX W3M

SASL2_DESC=	SASL2 support
SASL2_CONFIGURE_WITH=	cyrus-sasl
SASL2_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL2_LDFLAGS=-L${LOCALBASE}/lib
SASL2_CPPFLAGS=-I${LOCALBASE}/include

HASH_BKP_DESC=	Use hash as backup prefix (default is a comma)
HASH_BKP_CONFIGURE_WITH=	hash-backup

REPLYFILTER_DESC=	Install dependencies for contrib/replyfilter
REPLYFILTER_RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools \
				p5-Mail-Tools>=0:mail/p5-Mail-Tools \
				w3m>=0:www/w3m \
				par>=0:textproc/par

SMTP_DESC=	Use remote SMTP
SMTP_CONFIGURE_ON=	--with-mts=smtp
SENDMAIL_SMTP_DESC=	Use local sendmail (connect through socket)
SENDMAIL_SMTP_CONFIGURE_ON=	--with-mts=sendmail/smtp
SENDMAIL_PIPE_DESC=	Use local sendmail (connect through pipe)
SENDMAIL_PIPE_CONFIGURE_ON=	--with-mts=sendmail/pipe

DOT_DESC=	Dot file locking
DOT_CONFIGURE_ON=	--with-locking=dot
FCNTL_DESC=	fcntl() file locking
FCNTL_CONFIGURE_ON=	--with-locking=fcntl
FLOCK_DESC=	flock() file locking
FLOCK_CONFIGURE_ON=	--with-locking=flock
LOCKF_DESC=	lockf file locking
LOCKF_CONFIGURE_ON=	--with-locking=lockf

# The reason for BUILD_DEPENDS is nmh detects and configures itself for
# whichever text-based browser is installed.

ELINKS_DESC=	Install dependencies for www/elinks
ELINKS_BUILD_DEPENDS=	elinks>=0:www/elinks
ELINKS_RUN_DEPENDS=	elinks>=0:www/elinks

LINKS_DESC=	Install dependencies for www/links
LINKS_BUILD_DEPENDS=	links>=0:www/links
LINKS_RUN_DEPENDS=	links>=0:www/links

LYNX_DESC=	Install dependencies for www/lynx
LYNX_BUILD_DEPENDS=	lynx>=0:www/lynx
LYNX_RUN_DEPENDS=	lynx>=0:www/lynx

W3M_DESC=	Install dependencies for www/w3m
W3M_BUILD_DEPENDS=	w3m>=0:www/w3m
W3M_RUN_DEPENDS=	w3m>=0:www/w3m

OPTIONS_DEFAULT=	SENDMAIL_PIPE FLOCK W3M

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTLS}
CONFIGURE_ARGS+=	--with-tls
USES+=			ssl
.else
CONFIGURE_ARGS+=	--without-tls
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
LDFLAGS+=	-g
DEBUG_FLAGS+=	-O0 -Wall -Wextra -g
.endif

CONFLICTS_INSTALL=	ali ja-mh pixie p5-Dist-Joseki nmh-1.*

do-fetch:
	@cd ${DISTDIR} && \
	if [ ! -f ${DISTNAME}${EXTRACT_SUFX} ]; then \
		fetch -o ${DISTNAME}${EXTRACT_SUFX} \
		    "https://git.savannah.gnu.org/gitweb/?p=nmh.git;a=snapshot;h=${GIT_TAGNAME};sf=tgz"; \
	fi

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f -exec ${MV} {} {}-dist \;

.include <bsd.port.mk>
