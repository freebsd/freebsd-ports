# Created by: Tom Hukins <tom@eborcom.com>
# $FreeBSD$

# You can define the following to enable further compile time
# customizations:
# MAILDROP_SUID=<username>,
# MAILDROP_SGID=<groupname>     Maildrop will be installed with suid
#				permissions for MAILDROP_SUID, and sgid
#				permissions for MAILDROP_SGID.
#				NOTE: must be a valid username/groupname
#				at installation time, numeric uids/gids
#				and non existing users will cause the
#				installed package to miss files.
# MAILDROP_TRUSTED_USERS=<user> Specify users allowed to use the -d option
# MAILDROP_LOG_COLUMNS	lenght of 'File:' line in log - 8; default: 72
# MAILDROP_MBOX_DIR=<dir>	Specify DEFAULT mailbox location

PORTNAME=	maildrop
PORTVERSION=	2.8.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Mail delivery agent (MDA) with filtering abilities

LICENSE=	GPLv3

USES=		iconv perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-syslog=1 \
		--enable-use-flock=1 \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildirquota
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	courier-0.65* libunicode-[0-9]*

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libcourier-unicode.so:devel/courier-unicode

MAILDROP_LOG_COLUMNS?=	72	# lenght of 'File:' line in log

FIXDOCPATH=	libs/liblock/lockmail.1 libs/maildir/deliverquota.8.in \
		libs/maildir/maildir.5 libs/maildir/maildiracl.1.in \
		libs/maildir/maildirkw.1 libs/maildir/maildirmake.1.in \
		libs/maildir/maildirquota.7 libs/maildrop/mailbot.1 \
		libs/maildrop/maildrop.1.in libs/maildrop/maildropex.7 \
		libs/maildrop/maildropfilter.7.in libs/maildrop/maildropgdbm.7 \
		libs/maildrop/reformail.1 \
		libs/rfc2045/makemime.1 libs/rfc2045/reformime.1 \
		libs/rfc2045/rfc2045.3 libs/rfc822/rfc822.3

DOCS=	AUTHORS INSTALL INSTALL.html README README.html README.postfix \
	UPGRADE UPGRADE.html maildroptips.txt maildir/README.*

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.opt)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"
OPTIONS_MULTI_AUTHLIB:=	${OPTIONS_DEFINE:NDOCS}
OPTIONS_DEFINE=		AUTHLIB
OPTIONS_MULTI=		AUTHLIB
AUTHLIB_DESC=		Courier Auth Library support
.endif

OPTIONS_DEFINE+=	DOVECOTAUTH FAM GDBM IDN MAILWRAPPER DOCS

DOVECOTAUTH_DESC=	Dovecot Authentication support
MAILWRAPPER_DESC=	Let configure guess which sendmail binary to use

OPTIONS_SUB=		yes
GDBM_CONFIGURE_ON=	--with-db=gdbm
GDBM_CONFIGURE_OFF=	--with-db=db
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
IDN_CONFIGURE_WITH=	libidn
IDN_LIB_DEPENDS=	libidn.so:dns/libidn
MAILWRAPPER_CONFIGURE_OFF=	--enable-sendmail=/usr/sbin/sendmail
DOVECOTAUTH_CONFIGURE_ENABLE=	dovecotauth

.include <bsd.port.options.mk>

.if defined(MAILDROP_SUID) && defined(MAILDROP_SGID)
CONFIGURE_ARGS+=	--enable-maildrop-uid="${MAILDROP_SUID}" --enable-maildrop-gid="${MAILDROP_SGID}"
PLIST_SUB+=		MMODE='6755' MUID='${MAILDROP_SUID}' MGID='${MAILDROP_SGID}'
.elif defined(MAILDROP_SUID)
CONFIGURE_ARGS+=	--enable-maildrop-uid="${MAILDROP_SUID}"
PLIST_SUB+=		MMODE='4755' MUID='${MAILDROP_SUID}' MGID='mail'
.elif defined(MAILDROP_SGID)
CONFIGURE_ARGS+=	--enable-maildrop-gid="${MAILDROP_SGID}"
PLIST_SUB+=		MMODE='2755' MGID='${MAILDROP_SGID}' MUID='root'
.else
PLIST_SUB+=		MMODE='' MUID='root' MGID='mail'
.endif

.if defined(MAILDROP_MBOX_DIR)
CONFIGURE_ARGS+=	--with-default-maildrop='${MAILDROP_MBOX_DIR}'
.endif

.if ${PORT_OPTIONS:MFAM}
USES+=			fam
.else
CONFIGURE_ARGS+=	ac_cv_header_fam_h=no ac_cv_lib_fam_FAMOpen=no
.endif

.if defined(MAILDROP_TRUSTED_USERS)
CONFIGURE_ARGS+=	--enable-trusted-users="${MAILDROP_TRUSTED_USERS}"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/l= 72 - szbuf.Length();/l= ${MAILDROP_LOG_COLUMNS} - szbuf.Length();/" \
		${WRKSRC}/libs/maildrop/log.C
.for f in ${FIXDOCPATH}
	@${REINPLACE_CMD} -e "s|\\\%\[set \$$man\.base\.url\.for\.relative\.links\]|${DOCSDIR}|" \
		-e "s/\(maildirmake.html\)/maildrop-\1/" \
		-e "s/\(deliverquota.html\)/maildrop-\1/" ${WRKSRC}/${f}
.endfor
.if ${PORT_OPTIONS:MAUTHLIB}
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -L${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/libs/maildrop/Makefile.in
.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif
BUILD_DEPENDS+=	courierauthconfig:security/courier-authlib-base
RUN_DEPENDS+=	courierauthconfig:security/courier-authlib-base
CONFIGURE_ARGS+=	--enable-authlib
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

post-install:
.if ${PORT_OPTIONS:MDOVECOTAUTH}
	${INSTALL_DATA} ${WRKSRC}/README.dovecotauth ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/libs/maildir/quotawarnmsg \
		${STAGEDIR}${PREFIX}/etc/quotawarnmsg.sample
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS:S/maildir\//libs\/&/} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
