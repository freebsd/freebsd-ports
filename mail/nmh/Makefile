# Created by: Scott Blachowicz <scott+ports@sabami.seaslug.org>
# $FreeBSD$

PORTNAME=	nmh
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	nmh

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A cleaned up MH mailer suite

LICENSE=	BSD3CLAUSE

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh \
		--docdir=${DOCSDIR}

.ifdef NMH_EDITOR
CONFIGURE_ARGS+=	--with-editor=${NMH_EDITOR}
.endif
.ifdef NMH_MASQUERADE
CONFIGURE_ARGS+=	--enable-masquerade="${NMH_MASQUERADE}"
.endif
.ifdef NMH_PAGER
CONFIGURE_ARGS+=	--with-pager=${NMH_PAGER}
.endif
.ifdef NMH_SMTPSERVERS
CONFIGURE_ARGS+=	--with-smtpservers="${NMH_SMTPSERVERS}"
.endif

.ifdef NMH_EXTRA_CONFIGURE_ARGS
CONFIGURE_ARGS+=	${NMH_EXTRA_CONFIGURE_ARGS}
.endif
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS HASH_BKP SASL2 TLS REPLYFILTER
OPTIONS_SINGLE=	MTS LOCKING
OPTIONS_SINGLE_MTS=	SMTP SENDMAIL
OPTIONS_SINGLE_LOCKING=	DOT FCNTL FLOCK LOCKF

SASL2_DESC=	SASL2 support
SASL2_CONFIGURE_ON=	--with-cyrus-sasl
SASL2_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
SASL2_LDFLAGS=-L${LOCALBASE}/lib
SASL2_CPPFLAGS=-I${LOCALBASE}/include
HASH_BKP_DESC=	Use hash as backup prefix (default is a comma)
HASH_BKP_CONFIGURE_ON=	--with-hash-backup
REPLYFILTER_DESC=	Install dependencies for contrib/replyfilter
REPLYFILTER_RUN_DEPENDS=	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
				p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools

SMTP_DESC=	Use remote SMTP
SMTP_CONFIGURE_ON=	--with-mts=smtp
SENDMAIL_DESC=	Use local sendmail
SENDMAIL_CONFIGURE_ON=	--with-mts=sendmail

DOT_DESC=	Dot file locking
DOT_CONFIGURE_ON=	--with-locking=dot
FCNTL_DESC=	fcntl() file locking
FCNTL_CONFIGURE_ON=	--with-locking=fcntl
FLOCK_DESC=	flock() file locking
FLOCK_CONFIGURE_ON=	--with-locking=flock
LOCKF_DESC=	lockf file locking
LOCKF_CONFIGURE_ON=	--with-locking=lockf

OPTIONS_DEFAULT=	SMTP DOT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTLS}
CONFIGURE_ARGS+=	--with-tls
USE_OPENSSL=	yes
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
LDFLAGS+=	-g
DEBUG_FLAGS+=	-O0 -Wall -Wextra -g
.endif

CONFLICTS=	ja-mh-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e "s|autoconf|${AUTOCONF}|;\
		s|autoheader|${AUTOHEADER}|" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
