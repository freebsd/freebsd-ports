# Created by: Tom Hukins <tom@eborcom.com>
# $FreeBSD$

# You can define the following to enable further compile time
# customizations:
# MAILDROP_SUID=<uid>,
# MAILDROP_SGID=<gid>	Maildrop will be installed with suid permissions for
#			MAILDROP_SUID, and sgid permissions for MAILDROP_SGID.
# MAILDROP_TRUSTED_USERS=<user> Specify users allowed to use the -d option
# MAILDROP_LOG_COLUMNS	lenght of 'File:' line in log - 8; default: 72

PORTNAME=	maildrop
PORTVERSION=	2.7.1
CATEGORIES=	mail
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Mail delivery agent (MDA) with filtering abilities

LICENSE=	GPLv3

USES=		iconv shebangfix perl5 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-syslog=1 \
		--enable-use-flock=1 \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildirquota
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	libs/unicode/*.pl

CONFLICTS=	courier-0.65*

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre

MAILDROP_LOG_COLUMNS?=	72	# lenght of 'File:' line in log

FIXDOCPATH=	libs/liblock/lockmail.1 libs/maildir/deliverquota.8.in \
		libs/maildir/maildir.5 libs/maildir/maildiracl.1.in \
		libs/maildir/maildirkw.1 libs/maildir/maildirmake.1.in \
		libs/maildir/maildirquota.7 libs/maildrop/mailbot.1 \
		libs/maildrop/maildrop.1.in libs/maildrop/maildropex.7 \
		libs/maildrop/maildropfilter.7.in libs/maildrop/maildropgdbm.7 \
		libs/maildrop/makedat.1 libs/maildrop/reformail.1 \
		libs/rfc2045/makemime.1 libs/rfc2045/reformime.1 \
		libs/rfc2045/rfc2045.3 libs/rfc822/rfc822.3

DOCS=	AUTHORS INSTALL INSTALL.html README README.html README.postfix \
	UPGRADE UPGRADE.html maildroptips.txt maildir/README.*

.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.opt)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"
OPTIONS_MULTI_AUTHLIB:=	${OPTIONS_DEFINE}
OPTIONS_DEFINE=		AUTHLIB
OPTIONS_MULTI=		AUTHLIB
AUTHLIB_DESC=		Courier Auth Library support
.endif

OPTIONS_DEFINE+=	DOVECOTAUTH FAM GDBM MAILWRAPPER

DOVECOTAUTH_DESC=	Dovecot Authentication support
MAILWRAPPER_DESC=	Let configure guess which sendmail binary to use

OPTIONS_SUB=		yes
GDBM_CONFIGURE_ON=	--with-db=gdbm
GDBM_CONFIGURE_OFF=	--with-db=db
GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm

.include <bsd.port.options.mk>

.if defined(MAILDROP_SUID)
CONFIGURE_ARGS+=	--enable-maildrop-uid="${MAILDROP_SUID}"
PLIST_SUB+=		MSUID='' MUID='${MAILDROP_SUID}'
.else
PLIST_SUB+=		MSUID='@comment ' MUID='root'
.endif

.if defined(MAILDROP_SGID)
CONFIGURE_ARGS+=	--enable-maildrop-gid="${MAILDROP_SGID}"
PLIST_SUB+=		MSGID='' MGID='${MAILDROP_SGID}'
.else
PLIST_SUB+=		MSGID='@comment ' MGID='mail'
.endif

.if ! ${PORT_OPTIONS:MMAILWRAPPER}
CONFIGURE_ARGS+=	--enable-sendmail=/usr/sbin/sendmail
.endif

.if ${PORT_OPTIONS:MFAM} || exists(${LOCALBASE}/lib/libfam.so.0)
USES+=			fam
.endif

.if defined(MAILDROP_TRUSTED_USERS)
CONFIGURE_ARGS+=	--enable-trusted-users="${MAILDROP_TRUSTED_USERS}"
.endif

.if ${PORT_OPTIONS:MDOVECOTAUTH}
PATCH_SITES=	http://www.madpilot.net/maildrop/
PATCHFILES=	maildrop-2.7.0-dovecotauth.patch.txt
PATCH_DIST_STRIP=	-p1
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
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ -rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/libs/maildrop/Makefile.in
.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif
BUILD_DEPENDS+=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS+=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
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
.if defined(MAILDROP_SUID)
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/lockmail ${STAGEDIR}${PREFIX}/bin/maildrop
.endif
.if defined(MAILDROP_SGID)
	${CHMOD} g+s ${STAGEDIR}${PREFIX}/bin/lockmail ${STAGEDIR}${PREFIX}/bin/maildrop
.endif

.include <bsd.port.mk>
