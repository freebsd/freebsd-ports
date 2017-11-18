# Created by: Scott Blachowicz <scott+ports@sabami.seaslug.org>
# $FreeBSD$

PORTNAME=	nmh
PORTVERSION=	1.7
CATEGORIES=	mail
MASTER_SITES=	SAVANNAH

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Cleaned up MH mailer suite

LICENSE=	BSD3CLAUSE

USES=		cpe gmake iconv ncurses readline shebangfix
SHEBANG_FILES=	docs/contrib/ml docs/contrib/replyfilter docs/contrib/vpick
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc \
		--docdir=${DOCSDIR}
LIB_DEPENDS=	libcurl.so:ftp/curl

OPTIONS_DEFINE=	DOCS HASH_BKP SASL2 TLS REPLYFILTER
OPTIONS_SINGLE=	MTS LOCKING
OPTIONS_SINGLE_MTS=	SMTP SENDMAIL_SMTP SENDMAIL_PIPE
OPTIONS_SINGLE_LOCKING=	DOT FCNTL FLOCK LOCKF

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

OPTIONS_DEFAULT=	SMTP FLOCK

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

CONFLICTS=	ja-mh-[0-9]*
CONFLICTS_INSTALL=	pixie-* p5-Dist-Joseki-*

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f -exec ${MV} {} {}-dist \;

.include <bsd.port.mk>
