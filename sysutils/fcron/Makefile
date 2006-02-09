# ex:ts=8
# New ports collection makefile for:	fcron
# Date created:			Mar 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcron
PORTVERSION=	3.0.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/archives/ \
		ftp://ftp.seul.org/pub/fcron/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	huntting@glarp.com
COMMENT=	A periodic command scheduler

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-docdir=${DOCSDIR}

WRKSRC=		${WRKDIR}/fcron-${PORTVERSION}

USE_RC_SUBR=	fcron
SUB_FILES=	pkg-message

MAN1=		fcrontab.1
MAN5=		fcron.conf.5 fcrontab.5
MAN8=		fcron.8

PORTDOCS=	*

.if defined(MANLANG) && exists(${WRKSRC}/doc/${MANLANG})
DOCSRC=		${WRKSRC}/doc/${MANLANG}
.else
DOCSRC=		${WRKSRC}/doc/en
.endif

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
