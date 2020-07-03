# $FreeBSD$

PORTNAME=	fidogate
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7
CATEGORIES=	news mail

MAINTAINER=	admin@5034.ru
COMMENT=	Fido-Internet Gateway and Tosser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	autoreconf perl5 iconv

CONFLICTS=	fidogate-4* fidogate4-4*

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

DOCS=	doc/README.ru doc/README doc/FAQ.ru doc/old/ChangeLog doc/old/Changes.ru \
	doc/old/FAQ_fidogate doc/old/FIDOGATE_ftrack doc/old/README.snp \
	doc/old/fidogate.txt doc/old/fidogate.texi doc/old/msgid.doc

PLIST_SUB+=	SPOOLDIR=${SPOOLDIR} \
		SPOOLDIR2=${SPOOLDIR:S=/gate$==} \
		BTBASEDIR=${BTBASEDIR} \
		LOGDIR=${LOGDIR} \
		LOGDIR2=${LOGDIR:S=/gate$==} \
		LOCKDIR=${LOCKDIR} \
		VARDIR=${VARDIR} \
		PREFIX=${PREFIX}

OPTIONS_DEFINE=	INN DESCDIR ALIASES DBC DNT_NETMAIL FMSGID AVAIL BEST_AKA DOCS EXAMPLES
SPOOLDIR?=	/var/spool/fido/gate
BTBASEDIR?=	/var/spool/fido/bt
LOCKDIR?=	/var/run/fidogate
LOGDIR?=	/var/log/fido/gate
VARDIR?=	/var/db/fidogate

OPTIONS_DEFAULT=	INN DESCDIR FMSGID AVAIL BEST_AKA
NO_OPTIONS_SORT=yes

INN_BUILD_DEPENDS=	${PREFIX}/news/bin/innconfval:news/inn
INN_CONFIGURE_ON=	--with-inndir=${PREFIX}/news
INN_CONFIGURE_OFF=	--without-news
DESCDIR_CONFIGURE_OFF=	--disable-desc-dir
ALIASES_CONFIGURE_ON=	--enable-aliases-local
DBC_CONFIGURE_ON=	--enable-dbc-history
DNT_NETMAIL_CONFIGURE_ON=	--enable-dnt-netmail
FMSGID_CONFIGURE_OFF=	--disable-fs-msgid
AVAIL_CONFIGURE_OFF=	--disable-af-avail
BEST_AKA_CONFIGURE_ON=	--enable-best-aka

INN_DESC=	INN news server support
DESCDIR_DESC=	Put file descriptions into files.bbs
ALIASES_DESC=	Rewrite addresses found in ALIASES
DBC_DESC=	Use msgid correspond data base
DNT_NETMAIL_DESC=	Do not toss netmail
FMSGID_DESC=	Set gate msgid into outgoing messages
AVAIL_DESC=	Change behavior of "%list" and "%avail" commands
BEST_AKA_DESC=	Best AKA select

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

.include <bsd.port.mk>
