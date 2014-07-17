# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcron
PORTVERSION=	3.0.6
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/archives/ \
		ftp://ftp.seul.org/pub/fcron/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	rde@tavi.co.uk
COMMENT=	Periodic command scheduler

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes
USES=		perl5 gmake
USE_PERL5=	build
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --localstatedir=/var \
		--with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-docdir=${DOCSDIR}

WRKSRC=		${WRKDIR}/fcron-${PORTVERSION}

USERS=		fcron
GROUPS=		fcron

USE_RC_SUBR=	fcron
SUB_FILES=	pkg-message

PAMDIR?=	/etc/pam.d
PLIST_SUB+=	PAMDIR=etc/pam.d

PORTDOCS=	*

.if defined(MANLANG) && exists(${WRKSRC}/doc/${MANLANG})
DOCSRC=		${WRKSRC}/doc/${MANLANG}
.else
DOCSRC=		${WRKSRC}/doc/en
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcron ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/fcrontab ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fcrondyn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fcronsighup ${STAGEDIR}${PREFIX}/bin
.for f in fcron.allow fcron.conf fcron.deny
	${INSTALL_DATA} -m 640 ${WRKSRC}/files/${f} ${STAGEDIR}${PREFIX}/etc/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/fcrontab-* ${WRKSRC}/files/*.pam ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/files/fcron.pam ${STAGEDIR}${PREFIX}${PAMDIR}/fcron
	${INSTALL_DATA} ${WRKSRC}/files/fcrontab.pam ${STAGEDIR}${PREFIX}${PAMDIR}/fcrontab
	install -d -m 770 ${STAGEDIR}/var/spool/fcron
.for n in 1 5 8
	${INSTALL_MAN} ${DOCSRC}/man/*.${n} ${STAGEDIR}${PREFIX}/man/man${n}
.endfor
.for d in txt HTML
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	${INSTALL_DATA} ${DOCSRC}/${d}/* ${STAGEDIR}${DOCSDIR}/${d}
.endfor

.include <bsd.port.mk>
