# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcron
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/archives/ \
		ftp://ftp.seul.org/pub/fcron/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	rde@tavi.co.uk
COMMENT=	A periodic command scheduler

GNU_CONFIGURE=	yes
USES=		perl5 gmake
USE_PERL5=	build
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --localstatedir=/var \
		--with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-docdir=${DOCSDIR}

WRKSRC=		${WRKDIR}/fcron-${PORTVERSION}

USE_RC_SUBR=	fcron
SUB_FILES=	pkg-message

MAN1=		fcrontab.1
MAN5=		fcron.conf.5 fcrontab.5
MAN8=		fcron.8

PAMDIR?=	/etc/pam.d
PLIST_SUB+=	PAMDIR=etc/pam.d

PORTDOCS=	*

.if defined(MANLANG) && exists(${WRKSRC}/doc/${MANLANG})
DOCSRC=		${WRKSRC}/doc/${MANLANG}
.else
DOCSRC=		${WRKSRC}/doc/en
.endif

LICENSE=	GPLv2

NO_STAGE=	yes
pre-su-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcron ${PREFIX}/sbin
	${INSTALL_PROGRAM} -g fcron -o fcron -m 6111 ${WRKSRC}/fcrontab ${PREFIX}/bin
	${INSTALL_PROGRAM} -g fcron -o fcron -m 6111 ${WRKSRC}/fcrondyn ${PREFIX}/bin
	${INSTALL_PROGRAM} -g fcron -m 4110 ${WRKSRC}/fcronsighup ${PREFIX}/bin
.for f in fcron.allow fcron.conf fcron.deny
	${INSTALL_DATA} -g fcron -m 640 ${WRKSRC}/files/${f} ${PREFIX}/etc/${f}.dist
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/fcrontab-* ${WRKSRC}/files/*.pam ${EXAMPLESDIR}
	${MKDIR} ${PAMDIR}
	[ -f ${PAMDIR}/fcron ] || ${INSTALL_DATA} ${WRKSRC}/files/fcron.pam ${PAMDIR}/fcron
	[ -f ${PAMDIR}/fcrontab ] || ${INSTALL_DATA} ${WRKSRC}/files/fcrontab.pam ${PAMDIR}/fcrontab
.for n in 1 5 8
	${INSTALL_MAN} ${MAN${n}:S|^|${DOCSRC}/man/|} ${PREFIX}/man/man${n}
.endfor
.if !defined(NOPORTDOCS)
.  for d in txt HTML
	${MKDIR} ${DOCSDIR}/${d}
	${INSTALL_DATA} ${DOCSRC}/${d}/* ${DOCSDIR}/${d}
.  endfor
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
