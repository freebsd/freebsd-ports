PORTNAME=	fidogate
DISTVERSIONPREFIX=	v
DISTVERSION=	5.10-3
DISTVERSIONSUFFIX=	-g1c1fd41
CATEGORIES=	news mail

MAINTAINER=	admin@5034.ru
COMMENT=	Fido-Internet Gateway and Tosser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	autoreconf perl5 iconv

USE_GITHUB=	yes
GH_ACCOUNT=	ykaliuta
GH_PROJECT=	fidogate

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libexec=${PREFIX}/libexec/fidogate \
		--sysconfdir=${PREFIX}/etc/fido/gate \
		--with-lockdir=${LOCKDIR} \
		--with-logdir=${LOGDIR} \
		--with-vardir=${VARDIR} \
		--with-spooldir=${SPOOLDIR} \
		--with-btbasedir=${BTBASEDIR} \
		${ICONV_CONFIGURE_BASE}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=	install-strip

CONFLICTS=	fidogate-4* fidogate4-4*

PLIST_SUB+=	SPOOLDIR=${SPOOLDIR} \
		SPOOLDIR2=${SPOOLDIR:S=/gate$==} \
		BTBASEDIR=${BTBASEDIR} \
		LOGDIR=${LOGDIR} \
		LOGDIR2=${LOGDIR:S=/gate$==} \
		LOCKDIR=${LOCKDIR} \
		VARDIR=${VARDIR} \
		PREFIX=${PREFIX}

OPTIONS_DEFINE=	INN DESCDIR ALIASES DBC DNT_NETMAIL FMSGID AVAIL \
		BEST_AKA DOCS EXAMPLES FIX_QUOTE_RFC2FTN
OPTIONS_DEFAULT=	INN DESCDIR FMSGID AVAIL BEST_AKA FIX_QUOTE_RFC2FTN
NO_OPTIONS_SORT=yes

ALIASES_DESC=	Rewrite addresses found in ALIASES
AVAIL_DESC=	Change behaviour of areafix command "%list" and "%avail"
BEST_AKA_DESC=	Best AKA select
DBC_DESC=	Use msgid correspond data base
DESCDIR_DESC=	Put file descriptions into files.bbs
DNT_NETMAIL_DESC=	Do not toss netmail
FIX_QUOTE_RFC2FTN_DESC=	Fix quoting rfc2ftn
FMSGID_DESC=	Set gate msgid into outgoing messages
INN_DESC=	INN news server support

ALIASES_CONFIGURE_ON=	--enable-aliases-local
AVAIL_CONFIGURE_OFF=	--disable-af-avail
BEST_AKA_CONFIGURE_ON=	--enable-best-aka
DBC_CONFIGURE_ON=	--enable-dbc-history
DESCDIR_CONFIGURE_OFF=	--disable-desc-dir
DNT_NETMAIL_CONFIGURE_ON=	--enable-dnt-netmail
FIX_QUOTE_RFC2FTN_CONFIGURE_ON=	--enable-xct
FMSGID_CONFIGURE_OFF=	--disable-fs-msgid
INN_BUILD_DEPENDS=	${PREFIX}/news/bin/innconfval:news/inn
INN_CONFIGURE_ON=	--with-inndir=${PREFIX}/news
INN_CONFIGURE_OFF=	--without-news

DOCS=	doc/README.ru doc/README doc/FAQ.ru doc/old/ChangeLog doc/old/Changes.ru \
	doc/old/FAQ_fidogate doc/old/FIDOGATE_ftrack doc/old/README.snp \
	doc/old/fidogate.txt doc/old/fidogate.texi doc/old/msgid.doc

BTBASEDIR?=	/var/spool/fido/bt
LOCKDIR?=	/var/run/fidogate
LOGDIR?=	/var/log/fido/gate
SPOOLDIR?=	/var/spool/fido/gate
VARDIR?=	/var/db/fidogate

post-install:
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${LOCKDIR}
	${MKDIR} ${STAGEDIR}${VARDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/fidogate.conf-newsyslog \
	${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/fidogate.conf
	${MKDIR} ${STAGEDIR}${BTBASEDIR}/fbox \
		${STAGEDIR}${BTBASEDIR}/out

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for a in ${DOCS}
	${INSTALL_DATA}	${WRKSRC}/${a} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for a in exim inn postfix sendmail
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${a}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/news/inn/newsfeeds.fidogate ${STAGEDIR}${EXAMPLESDIR}/inn/newsfeeds.fidogate
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/postfix/master.cf ${STAGEDIR}${EXAMPLESDIR}/postfix/master.cf
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/postfix/transport ${STAGEDIR}${EXAMPLESDIR}/postfix/transport
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/sendmail/mailer/ftn.m4 ${STAGEDIR}${EXAMPLESDIR}/sendmail/ftn.m4
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/exim/exim.conf.in ${STAGEDIR}${EXAMPLESDIR}/exim/exim.conf.in
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/exim/ftntable_1304 ${STAGEDIR}${EXAMPLESDIR}/exim/ftntable_1304
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/exim/ftntable_1309 ${STAGEDIR}${EXAMPLESDIR}/exim/ftntable_1309
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/exim/ftntable_local ${STAGEDIR}${EXAMPLESDIR}/exim/ftntable_local

post-install-EXAMPLES-on:

.include <bsd.port.pre.mk>
.if ${PORT_OPTIONS:MFIX_QUOTE_RFC2FTN}
PLIST_SUB+=	FIX_QUOTE_RFC2FTN=""
.else
PLIST_SUB+=	FIX_QUOTE_RFC2FTN="@comment "
.endif

.include <bsd.port.post.mk>
