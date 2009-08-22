# New ports collection makefile for: fidogateds
# Whom:                 Andrey Slusar <anray@FreeBSD.org>
# Date created:         9 Feb 2004
# $FreeBSD$
#

PORTNAME=		fidogate
PORTVERSION=		5.1.7
PORTREVISION=		1
CATEGORIES=		news mail
MASTER_SITES=		SF/rus${PORTNAME}/${PORTNAME}-stable/${PORTNAME}%20${PORTVERSION}ds
PKGNAMESUFFIX=		-ds
DISTNAME=		fidogate${PORTVERSION}ds

MAINTAINER=		anray@FreeBSD.org
COMMENT=		Fido-Internet Gateway and Tosser

.if !defined(WITHOUT_INN)
BUILD_DEPENDS=		${LOCALBASE}/news/bin/innconfval:${PORTSDIR}/news/inn
.endif

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_PERL5=		yes

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

HAS_CONFIGURE=		yes
.if defined(WITHOUT_INN) || defined (BATCH)
CONFIGURE_ARGS+=	--without-news
.else
CONFIGURE_ARGS+=	--with-newsbindir=${LOCALBASE}/news/bin
.endif
.if !defined(WITH_BSO)
CONFIGURE_ARGS+=	--enable-amiga-out
.endif
.if !defined(WITH_DESCDIR)
CONFIGURE_ARGS+=	--disable-desc-dir
.endif
.if !defined(WITHOUT_ALIASES)
CONFIGURE_ARGS+=	--enable-aliases-local
.endif
.if defined(WITH_DBC)
CONFIGURE_ARGS+=	--enable-dbc-history
.endif
.if defined(DNT_NETMAIL)
CONFIGURE_ARGS+=	--enable-dnt-netmail
.endif
.if defined(WITHOUT_FMSGID)
CONFIGURE_ARGS+=	--disable-fs-msgid
.endif
.if !defined(WITH_AVAIL)
CONFIGURE_ARGS+=	--disable-af-avail
.endif
.if defined(WITHOUT_BEST_AKA)
CONFIGURE_ARGS+=	--disable-best-aka
.endif
.if defined(WITH_NFS_LOCK)
CONFIGURE_ARGS+=	--enable-nfs-safe-lock
.endif
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

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for a in ${DOCS}
	${INSTALL_DATA}	${WRKSRC}/${a} ${DOCSDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for a in point inn postfix sendmail
	${MKDIR} ${EXAMPLESDIR}/${a}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/areas ${EXAMPLESDIR}/point/areas
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/areas.bbs ${EXAMPLESDIR}/point/areas.bbs
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/fidogate.conf ${EXAMPLESDIR}/point/fidogate.conf
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/newsfeeds ${EXAMPLESDIR}/point/newsfeeds
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/packing ${EXAMPLESDIR}/point/packing
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point/routing ${EXAMPLESDIR}/point/routing
	${INSTALL_DATA} ${WRKSRC}/doc/news/inn/newsfeeds.fidogate ${EXAMPLESDIR}/inn/newsfeeds.fidogate
	${INSTALL_DATA}	${WRKSRC}/doc/mailer/postfix/master.cf ${EXAMPLESDIR}/postfix/master.cf
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/postfix/transport ${EXAMPLESDIR}/postfix/transport
	${INSTALL_DATA} ${WRKSRC}/doc/mailer/sendmail/mailer/ftn.m4 ${EXAMPLESDIR}/sendmail/ftn.m4
.endif

.include <bsd.port.mk>
