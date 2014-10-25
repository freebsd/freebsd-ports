# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=		fidogate
PORTVERSION=		5.1.7
PORTREVISION=		3
CATEGORIES=		news mail
MASTER_SITES=		SF/rus${PORTNAME}/${PORTNAME}-stable/${PORTNAME}%20${PORTVERSION}ds
PKGNAMESUFFIX=		-ds
DISTNAME=		fidogate${PORTVERSION}ds

MAINTAINER=		5u623l20@gmail.com
COMMENT=		Fido-Internet Gateway and Tosser

BROKEN=			Fails to configure
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

PORTSCOUT=		limit:^5\.[^2] # 5.2.X is development branch

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=		yes
USES=		perl5 tar:bzip2
MAKE_JOBS_UNSAFE=	yes

SPOOLDIR?=/var/spool/fido/gate
BTBASEDIR?=/var/spool/fido/bt
LOCKDIR?=/var/run/fidogate
LOGDIR?=/var/log/fido/gate
VARDIR?=${PREFIX}/var/fidogate

PLIST_SUB+=		SPOOLDIR=${SPOOLDIR} \
			BTBASEDIR=${BTBASEDIR} \
			LOGDIR=${LOGDIR} \
			LOCKDIR=${LOCKDIR} \
			VARDIR=${VARDIR} \
			PREFIX=${PREFIX}

OPTIONS_DEFINE=	ALIASES AVAIL BEST_AKA BSO DBC DESCDIR DNT_NETMAIL DOCS FMSGID INN NFS_LOCK
OPTIONS_DEFAULT=ALIASES BEST_AKA BSO DOCS FMSGID INN 
ALIASES_DESC=	Enable local aliases
AVAIL_DESC=		Change %list and %avail behaviour
BEST_AKA_DESC=	Enable best AKA
BSO_DESC=		Create 4D outbound filenames for AmigaDOS mailers
DBC_DESC=		Use msgid correspond data base
DESCDIR_DESC=	Put file descriptions into files.bbs
DNT_NETMAIL_DESC=	Do not toss netmail
FMSGID_DESC=	Set gate msgid into outgoing messages
INN_DESC=		News support
NFS_LOCK_DESC=	Create lock files/BSY files in an NFS-safe way

ALIASES_CONFIGURE_ENABLE=	aliases-local
AVAIL_CONFIGURE_ENABLE=		af-avail
BEST_AKA_CONFIGURE_ENABLE=	best-aka
BSO_CONFIGURE_ENABLE=		amiga-out
DBC_CONFIGURE_ENABLE=		dbc-history
DESCDIR_CONFIGURE_ENABLE=	desc-dir
DNT_NETMAIL_CONFIGURE_ENABLE=	dnt-netmail
FMSGID_CONFIGURE_ENABLE=	fs-msgid
INN_BUILD_DEPENDS=			${LOCALBASE}/news/bin/innconfval:${PORTSDIR}/news/inn
INN_CONFIGURE_ON=			--with-newsbindir=${LOCALBASE}/news/bin
INN_CONFIGURE_OFF=			--without-news
NFS_LOCK_CONFIGURE_ENABLE=	nfs-safe-lock

CONFIGURE_ARGS+=	--libexec=${PREFIX}/libexec/fidogate \
			--sysconfdir=${PREFIX}/etc/fido/gate \
			--libdir=${PREFIX}/lib/fidogate \
			--with-lockdir=${LOCKDIR} \
			--with-logdir=${LOGDIR} \
			--with-vardir=${VARDIR} \
			--with-spooldir=${SPOOLDIR} \
			--with-btbasedir=${BTBASEDIR}

DOCS=		doc/README.ru doc/README doc/FAQ.ru doc/FIDOGATE+tracker.ru \
		ChangeLog Changes.ru doc/old/FAQ_fidogate doc/FAQ_Config.ru \
		doc/old/FIDOGATE_ftrack doc/old/README.snp \
		doc/old/fidogate.txt doc/old/fidogate.texi doc/old/msgid.doc

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for a in ${DOCS}
	${INSTALL_DATA}	${WRKSRC}/${a} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for a in point inn postfix sendmail
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${a}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/areas ${STAGEDIR}${EXAMPLESDIR}/point/areas
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/areas.bbs ${STAGEDIR}${EXAMPLESDIR}/point/areas.bbs
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/fidogate.conf ${STAGEDIR}${EXAMPLESDIR}/point/fidogate.conf
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/newsfeeds ${STAGEDIR}${EXAMPLESDIR}/point/newsfeeds
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/packing ${STAGEDIR}${EXAMPLESDIR}/point/packing
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/routing ${STAGEDIR}${EXAMPLESDIR}/point/routing
	${INSTALL_DATA} ${WRKSRC}/doc/news/inn/newsfeeds.fidogate ${STAGEDIR}${EXAMPLESDIR}/inn/newsfeeds.fidogate
	${INSTALL_DATA}	${WRKSRC}/doc/mailer/postfix/master.cf ${STAGEDIR}${EXAMPLESDIR}/postfix/master.cf
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/postfix/transport ${STAGEDIR}${EXAMPLESDIR}/postfix/transport
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/sendmail/mailer/ftn.m4 ${STAGEDIR}${EXAMPLESDIR}/sendmail/ftn.m4
.for i in toss/bad toss/pack toss/route toss/toss outrfc/mail outrfc/news outpkt/mail outpkt/news
	@${TOUCH} ${STAGEDIR}${SPOOLDIR}/$i/.keep_me
.endfor
.for i in in/bad in/tmpunpack pin/bad pin/tmpunpack tick
	@${TOUCH} ${STAGEDIR}${BTBASEDIR}/$i/.keep_me
.endfor
.for i in ${LOGDIR} ${LOCKDIR}
	@${TOUCH} ${STAGEDIR}$i/.keep_me
.endfor

.include <bsd.port.mk>
